/*
	A simple program that demonstrates how to program for a
	touch screen. Specifically on the Raspberry Pi.
	This prgram can be used for most Linux based systems.
	For more details: ozzmaker.com

    Copyright (C) 2013  Mark Williams

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
    MA 02111-1307, USA
*/

#include <linux/input.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include "touch.h"
#include "touch.c"
#include "framebuffer.c"
#include <signal.h>
#include <unistd.h>


void  INThandler(int sig)
{
  signal(sig, SIG_IGN);
	closeFramebuffer();
  exit(0);
}
extern void createButton(int x, int y, int w, int h, char *text, int backgroundColor, int foregroundColor);

typedef struct Point
{
	int x;
	int y;
} POINT;

typedef struct Matrix
{
	long An;
	long Bn;
	long Cn;
	long Dn;
	long En;
	long Fn;
	long Divider;
} MATRIX;

POINT screenPoint;		// touch screen point
POINT displayPoint;		// display(LCD) view point
MATRIX matrix;

int calibrationMatrix( POINT *lcdPtr, POINT *touchPtr, MATRIX *matrixPtr);
int getPoint(POINT *screenPoint);
void Touch_Calibrate(void);

static int An = 0xfff7be1e;
static int Bn = 0xffffef6d;
static int Cn = 0x7b3c8df;
static int Dn = 0x89e;
static int En = 0xfff9b55c;
static int Fn = 0x7346c4c;
static int Divider = 0xffa280fe;

int main()
{
  int xres, yres;
	signal(SIGINT, INThandler);
  POINT screenPoint;

	int screenXmax, screenXmin, scaleXvalue;
	int screenYmax, screenYmin, scaleYvalue;

	if (openTouchScreen() == 1)
		perror("error opening touch screen");


	getTouchScreenDetails(&screenXmin,&screenXmax,&screenYmin,&screenYmax);

	framebufferInitialize(&xres,&yres);

	scaleXvalue = ((float)screenXmax-screenXmin) / xres;
	printf ("X Scale Factor = %f\n", scaleXvalue);
	scaleYvalue = ((float)screenYmax-screenYmin) / yres;
	printf ("Y Scale Factor = %f\n", scaleYvalue);
  
  //createButton(20,20,100,100,"RED",GREY,RED);
  printf ("Start calibration\n");
 // Touch_Calibrate();
  printf ("matrix1: %x %x %x %x \n",matrix.An, matrix.Bn, matrix.Cn, matrix.Divider);
  printf ("matrix2: %x %x %x \n",matrix.Dn, matrix.En, matrix.Fn);
  printf ("Start calibration end\n");
  /*
  {32,24},{160,215},{287,120}
x,y=608,623
x,y=1693,2760
x,y=3118,2425
matrix1: fffb3459 ffff51c3 68b4b93 ffcbfcc4
matrix2: 21f16 fffa462e 405142e
Start calibration end

Start calibration
x,y=596,653
x,y=2023,3499
x,y=3472,2095
matrix1: 0xfff7be1e 0xffffef6d 0x7b3c8df 0xffa280fe
matrix2: 0x89e 0xfff9b55c 0x7346c4c
Start calibration end





static int An = 0xfff7be1e;
static int Bn = 0xffffef6d;
static int Cn = 0x7b3c8df;
static int Dn = 0x89e;
static int En = 0xfff9b55c;
static int Fn = 0x7346c4c;
static int Divider = 0xffa280fe;

x = ((An * x) + (Bn * y) + Cn) / Divider;
y = ((Dn * x) + (En * y) + Fn) / Divider;  
   
  */
	while(1)
  {
    while (getPoint(&screenPoint)==0 || screenPoint.x<0 || screenPoint.x > 4096 ||  screenPoint.y<0 || screenPoint.y > 4096);

    //displayPoint.x = ((matrix.An * screenPoint.x) + (matrix.Bn * screenPoint.y) + matrix.Cn) / matrix.Divider;
    //displayPoint.y = ((matrix.Dn * screenPoint.x) + (matrix.En * screenPoint.y) + matrix.Fn) / matrix.Divider;    
    
    displayPoint.x = ((An * screenPoint.x) + (Bn * screenPoint.y) + Cn) / Divider;
    displayPoint.y = ((Dn * screenPoint.x) + (En * screenPoint.y) + Fn) / Divider;  
    
    //if (displayPoint.x>0 && displayPoint.y>0 && displayPoint.x < 400 && displayPoint.y < 300) {
      printf("ADCx,ADCy=%d,%d\n",screenPoint.x, screenPoint.y);
      printf("x,y=%d,%d\n",displayPoint.x, displayPoint.y);
      drawSquare(displayPoint.x, displayPoint.y,3,3,WHITE);
    //}
	}
}

#define SAMPLE_AMOUNT 4

int getPoint(POINT *screenPoint)
{
  POINT displayPoint;
  int rawX, rawY, rawPressure, scaledX, scaledY;
  int sample;
	int Xsamples[SAMPLE_AMOUNT];
	int Ysamples[SAMPLE_AMOUNT];  
	int Xaverage = 0;
	int Yaverage = 0;
  int i;
  
	for (sample = 0; sample < SAMPLE_AMOUNT; sample++)
  {
			getTouchSample(&rawX, &rawY, &rawPressure);
			Xsamples[sample] = rawX;
			Ysamples[sample] = rawY;
	}

  Xaverage  = 0;
  Yaverage  = 0;
  for ( i = 0; i < SAMPLE_AMOUNT; i++ )
  {
			Xaverage += Xsamples[i];
			Yaverage += Ysamples[i];
  }

  Xaverage = Xaverage/SAMPLE_AMOUNT;
  Yaverage = Yaverage/SAMPLE_AMOUNT;
  screenPoint->x = Xaverage;
  screenPoint->y = Yaverage;
  return rawPressure;
}

void Touch_Calibrate(void)
{
    POINT Sample;
    POINT screenSample[3];   //array of input points
    POINT displaySample[3] = {{32,24},{160,215},{287,120}};  //array of expected correct answers  TS.getMatrix();
    unsigned char i;
    int val =0;
    
    for (i=0; i<3; i++)
    {
      drawSquare(displaySample[i].x, displaySample[i].y,5,5,WHITE);
      // got a point
      while (getPoint(&screenSample[i])==0);

      usleep(100000);
      val = getPoint(&screenSample[i]);
      while (val==0 || screenSample[i].x<0 || screenSample[i].x > 4096 ||  screenSample[i].y<0 || screenSample[i].y > 4096)
      {
        val = getPoint(&screenSample[i]);
      }
      drawSquare(displaySample[i].x, displaySample[i].y,5,5,RED);   
      while (getPoint(&Sample)==1) ;      
      usleep(1000000);
      
      printf("x,y=%d,%d\n",screenSample[i].x, screenSample[i].y);
    }
    calibrationMatrix(&displaySample[0], &screenSample[0], &matrix);  // calibration
}

int calibrationMatrix( POINT *lcdPtr, POINT *touchPtr, MATRIX *matrixPtr)
{
    int  retValue = 1 ;
    
    matrixPtr->Divider = ((touchPtr[0].x - touchPtr[2].x) * (touchPtr[1].y - touchPtr[2].y)) - 
                         ((touchPtr[1].x - touchPtr[2].x) * (touchPtr[0].y - touchPtr[2].y)) ;
    if( matrixPtr->Divider == 0 )
    {
        retValue = 0 ;
    }
    else
    {
        matrixPtr->An = ((lcdPtr[0].x - lcdPtr[2].x) * (touchPtr[1].y - touchPtr[2].y)) - 
                        ((lcdPtr[1].x - lcdPtr[2].x) * (touchPtr[0].y - touchPtr[2].y)) ;

        matrixPtr->Bn = ((touchPtr[0].x - touchPtr[2].x) * (lcdPtr[1].x - lcdPtr[2].x)) - 
                        ((lcdPtr[0].x - lcdPtr[2].x) * (touchPtr[1].x - touchPtr[2].x)) ;

        matrixPtr->Cn = (touchPtr[2].x * lcdPtr[1].x - touchPtr[1].x * lcdPtr[2].x) * touchPtr[0].y +
                        (touchPtr[0].x * lcdPtr[2].x - touchPtr[2].x * lcdPtr[0].x) * touchPtr[1].y +
                        (touchPtr[1].x * lcdPtr[0].x - touchPtr[0].x * lcdPtr[1].x) * touchPtr[2].y ;

        matrixPtr->Dn = ((lcdPtr[0].y - lcdPtr[2].y) * (touchPtr[1].y - touchPtr[2].y)) - 
                        ((lcdPtr[1].y - lcdPtr[2].y) * (touchPtr[0].y - touchPtr[2].y)) ;
    
        matrixPtr->En = ((touchPtr[0].x - touchPtr[2].x) * (lcdPtr[1].y - lcdPtr[2].y)) - 
                        ((lcdPtr[0].y - lcdPtr[2].y) * (touchPtr[1].x - touchPtr[2].x)) ;

        matrixPtr->Fn = (touchPtr[2].x * lcdPtr[1].y - touchPtr[1].x * lcdPtr[2].y) * touchPtr[0].y +
                        (touchPtr[0].x * lcdPtr[2].y - touchPtr[2].x * lcdPtr[0].y) * touchPtr[1].y +
                        (touchPtr[1].x * lcdPtr[0].y - touchPtr[0].x * lcdPtr[1].y) * touchPtr[2].y ;
    }
 
    return( retValue ) ;

}

