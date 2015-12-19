#include <QtGui>
#include <vector>

using namespace std;

#ifdef Q_WS_QWS
#define QTDEMO_EMULATE_KEYPRESS_STDIN
#define QTDEMO_BORDER_AROUND_FOCUS
#else /* !Q_WS_QWS */
#undef QTDEMO_EMULATE_KEYPRESS_STDIN
#undef QTDEMO_BORDER_AROUND_FOCUS
#endif /* Q_WS_QWS */

#ifndef QTDEMO_FOCUS_BORDER_WIDTH
#define QTDEMO_FOCUS_BORDER_WIDTH	2
#endif

class EmcPicBtn : public QPushButton
{
    Q_OBJECT
public:
    EmcPicBtn(QWidget *parent, int x, int y, const QString &img);
    virtual ~EmcPicBtn() {}

    void setSelected(bool enable);

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    QImage m_pressedImg, m_releasedImg, m_checkedImg;
    bool m_selected;
};

class EmcDlg : public QWidget
{
    Q_OBJECT
public:
    EmcDlg(QWidget *parent);
    virtual ~EmcDlg() {}

protected:
    virtual void paintEvent(QPaintEvent *)
    {
    }

    virtual void keyPressEvent(QKeyEvent *);

protected slots:
    virtual void saveClicked() = 0;
    virtual void cancelClicked() = 0;
    virtual void exitClicked() { hide(); }

protected:
    EmcPicBtn m_btnSave;
    EmcPicBtn m_btnCancel;
    EmcPicBtn m_btnExit;
};

class EmcFlowersDlg : public EmcDlg
{
    Q_OBJECT
public:
    EmcFlowersDlg(QWidget *parent);
    virtual ~EmcFlowersDlg() {}

    void setFlowersCount(unsigned int count);

private:
    virtual void saveClicked() {}
    virtual void cancelClicked() {}
    
private:
    QListWidget m_flowersView;
    vector<QListWidgetItem> m_items;
};

class EmcClockDlg : public EmcDlg
{
    Q_OBJECT
public:
    EmcClockDlg(QWidget *parent);
    virtual ~EmcClockDlg() {}

private:
    virtual void saveClicked()
    {
        m_date = m_dateEdit.date();
        m_time = m_timeEdit.time();
    }
    virtual void cancelClicked()
    {
        m_dateEdit.setDate(m_date);
        m_timeEdit.setTime(m_time);
    }
    
private:
    QDateEdit m_dateEdit;
    QTimeEdit m_timeEdit;
    QDate m_date;
    QTime m_time;
};

class EmcNotesDlg : public EmcDlg
{
    Q_OBJECT
public:
    EmcNotesDlg(QWidget *parent);
    virtual ~EmcNotesDlg() {}

    void setText(const QString &text)
    {
        m_textWidget.setText(text);
    }

private:
    virtual void saveClicked() {}
    virtual void cancelClicked() {}
    
private:
    QTextEdit m_textWidget;
};

class EmcTempDlg : public EmcDlg
{
    Q_OBJECT
public:
    EmcTempDlg(QWidget *parent);
    virtual ~EmcTempDlg() {}

public slots:
    void setTemp(int temp)
    {
        m_dial.setValue(temp);
        m_slider.setValue(temp);
    }

private:
    virtual void saveClicked() {}
    virtual void cancelClicked() {}
    
private:
    QDial m_dial;
    QSlider m_slider;
};

extern QAtomicInt lock;

class EmcDemoWidget : public QWidget
{
    Q_OBJECT
public:
    EmcDemoWidget();
    virtual ~EmcDemoWidget()
    {
        for (unsigned int i = 0; i < m_dlgs.size(); i++)
            delete m_dlgs[i];
    }

public slots:
    void kitchenClicked();
    void bedRoom1Clicked();
    void bedRoom2Clicked();
    void outsideClicked();

    void changePicture();
    void flowersClicked();
    void clockClicked();
    void notesClicked();

    void tempClicked();
    void exitClicked();
    void moveCursor(int x, int y)
    {
        QCursor::setPos(mapToGlobal(QPoint(x, y)));
        lock = 0;
    }
    void clickMouse()
    {
#if 0
        QApplication::postEvent(
            qApp->widgetAt(QCursor::pos()),
            new QMouseEvent(QEvent::MouseButtonPress, QPoint(5, 5),
                            Qt::LeftButton, Qt::LeftButton, Qt::NoModifier));
        QApplication::postEvent(qApp->widgetAt(QCursor::pos()),
            new QMouseEvent(QEvent::MouseButtonRelease, QPoint(5, 5),
                            Qt::LeftButton, Qt::LeftButton, Qt::NoModifier));
#else
        printf("w %p x %i y %i\n",
               qApp->widgetAt(QCursor::pos()),
               QCursor::pos().x(), QCursor::pos().y());
        ((QAbstractButton *)qApp->widgetAt(QCursor::pos()))->click();
        lock = 0;
#endif
    }

    void sendKeyPress(int keycode);

private:
    enum Places { KITCHEN, BEDROOM1, BEDROOM2, OUTSIDE, NOPLACE } m_curPlace;
    enum Funcs { FLOWERS, CLOCK, NOTES, TEMP, NOFUNC } m_curFunc;

protected:
    virtual void paintEvent(QPaintEvent * event);
    void updateView();
    void placeButtonClicked(enum Places place);
    void funcButtonClicked(enum Funcs func);

private:
    vector<QImage> m_img;
    int m_curImg;
    vector<EmcDlg *> m_dlgs;
    vector<EmcPicBtn *> m_placeButtons;
    vector<EmcPicBtn *> m_funcButtons;
    QButtonGroup m_buttonGroup;
    EmcPicBtn m_kitchenButton, m_bedRoom1Button, m_bedRoom2Button, m_outsideButton;
    EmcPicBtn m_flowersButton, m_clockButton, m_notesButton, m_tempButton;
    EmcPicBtn m_picChangeButton;
    int m_flowersCount[NOPLACE];
    QString m_notes[NOPLACE];
    int m_temp[NOPLACE];
};

class EmcDemoThread : public QThread
{
    Q_OBJECT
public:
    EmcDemoThread(EmcDemoWidget &win) : QThread(), m_win(win) {}
    void run();

signals:
    void moveCursor(int, int);
    void clickMouse();

private:
    EmcDemoWidget &m_win;
};

#ifdef QTDEMO_EMULATE_KEYPRESS_STDIN
class StdInputThread : public QThread
{
    Q_OBJECT
public:
    StdInputThread() : QThread() {}
    void run();
signals:
    void sendKeyPress(int keycode);
};
#endif /* QTDEMO_EMULATE_KEYPRESS_STDIN */
