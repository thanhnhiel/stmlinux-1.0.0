/*
 * This is a user-space application that reads /dev/sample
 * and prints the read characters to stdout
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	char * app_name = argv[0];
	char * dev_name = "/dev/input/event0";
	int ret = -1;
	int fd = -1;
	int count,i;
  char a[20];
  
  
  
  if (getenv("TSLIB_TSDEVICE")!= NULL)
    dev_name = getenv("TSLIB_TSDEVICE");

	/*
 	 * Open the sample device RD | WR
 	 */
   printf("open %s\n", dev_name);
   
	if ((fd = open(dev_name, O_RDWR  | O_NDELAY)) < 0) {
		fprintf(stderr, "%s: unable to open %s: %s\n", 
			app_name, dev_name, strerror(errno));
		goto Done;
	}

	/*
 	 * Read the sample device byte-by-byte
 	 */
	while (1) 
  {
    count = read(fd, a, 4);
		if (count > 0) 
    {
      fprintf(stdout,"event=");
      for (i=0;i<count;i++)
        fprintf(stdout,"%x ",a[i]);
      fprintf(stdout,"\n");
			//goto Done;
		}	
    if (count) fprintf(stdout,"end\n");
    
	}

	/*
 	 * If we are here, we have been successful
 	 */
	ret = 0;

Done:
	if (fd >= 0) {
		close(fd);
	}
	return ret;
}
