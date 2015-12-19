#include <QtGui>
#include <QThread>
#include <QWSServer>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include "qt.h"

#undef DEBUG_TIMES
#ifdef DEBUG_TIMES
/* Code to debug task execution times */
#define S(l) \
    struct timeval t1##l; \
    gettimeofday(&t1##l, NULL)

#define E(l) \
    struct timeval t2##l; \
    gettimeofday(&t2##l, NULL); \
    printf("%s: %lli\n", #l, (long long)t2##l.tv_sec*1000000 + t2##l.tv_usec - \
        (long long)t1##l.tv_sec*1000000 - t1##l.tv_usec)
#else
#define S(l) do {} while(0)
#define E(l) do {} while(0)
#endif

EmcDemoWidget::EmcDemoWidget() :
    QWidget(),
    m_curImg(0),

    m_kitchenButton(this, 8, 82, "button1"),
    m_bedRoom1Button(this, 8, 104, "button2"),
    m_bedRoom2Button(this, 8, 126, "button3"),
    m_outsideButton(this, 8, 206, "button4"),

    m_flowersButton(this, 17, 13, "flowers"),
    m_clockButton(this, 58, 13, "clock"),
    m_notesButton(this, 99, 13, "notes"),
    m_tempButton(this, 140, 13, "temp"),

    m_picChangeButton(this, 420, 13, "forward")
{
    m_img.push_back(QImage("pics/backgr.bmp"));
    m_img.push_back(QImage("pics/backgr_1.bmp"));
    m_img.push_back(QImage("pics/backgr_2.bmp"));

    setGeometry(0, 0, 480, 272);

    m_buttonGroup.addButton(&m_kitchenButton);
    QObject::connect(&m_kitchenButton, SIGNAL(clicked()),
                     this, SLOT(kitchenClicked()));

    m_buttonGroup.addButton(&m_bedRoom1Button);
    QObject::connect(&m_bedRoom1Button, SIGNAL(clicked()),
                     this, SLOT(bedRoom1Clicked()));

    m_buttonGroup.addButton(&m_bedRoom2Button);
    QObject::connect(&m_bedRoom2Button, SIGNAL(clicked()),
                     this, SLOT(bedRoom2Clicked()));

    m_buttonGroup.addButton(&m_outsideButton);
    QObject::connect(&m_outsideButton, SIGNAL(clicked()),
                     this, SLOT(outsideClicked()));

    m_placeButtons.push_back(&m_kitchenButton);
    m_placeButtons.push_back(&m_bedRoom1Button);
    m_placeButtons.push_back(&m_bedRoom2Button);
    m_placeButtons.push_back(&m_outsideButton);

    m_buttonGroup.addButton(&m_flowersButton);
    QObject::connect(&m_flowersButton, SIGNAL(clicked()),
                     this, SLOT(flowersClicked()));

    m_buttonGroup.addButton(&m_clockButton);
    QObject::connect(&m_clockButton, SIGNAL(clicked()),
                     this, SLOT(clockClicked()));

    m_buttonGroup.addButton(&m_notesButton);
    QObject::connect(&m_notesButton, SIGNAL(clicked()),
                     this, SLOT(notesClicked()));

    m_buttonGroup.addButton(&m_tempButton);
    QObject::connect(&m_tempButton, SIGNAL(clicked()),
                     this, SLOT(tempClicked()));

    m_buttonGroup.addButton(&m_picChangeButton);
    QObject::connect(&m_picChangeButton, SIGNAL(clicked()),
                     this, SLOT(changePicture()));

    m_funcButtons.push_back(&m_flowersButton);
    m_funcButtons.push_back(&m_clockButton);
    m_funcButtons.push_back(&m_notesButton);
    m_funcButtons.push_back(&m_tempButton);

    m_dlgs.push_back(new EmcFlowersDlg(this));
    m_dlgs.push_back(new EmcClockDlg(this));
    m_dlgs.push_back(new EmcNotesDlg(this));
    m_dlgs.push_back(new EmcTempDlg(this));

    m_flowersCount[KITCHEN] = 6;
    m_flowersCount[BEDROOM1] = 11;
    m_flowersCount[BEDROOM2] = 9;
    m_flowersCount[OUTSIDE] = 51;

    QFile file("kitchen_notes.htm");
    if (file.open(QIODevice::ReadOnly))
        m_notes[KITCHEN] = file.readAll();
    QFile file1("bedroom1_notes.htm");
    if (file1.open(QIODevice::ReadOnly))
        m_notes[BEDROOM1] = file1.readAll();
    QFile file2("bedroom2_notes.htm");
    if (file2.open(QIODevice::ReadOnly))
        m_notes[BEDROOM2] = file2.readAll();
    QFile file3("outside_notes.htm");
    if (file3.open(QIODevice::ReadOnly))
        m_notes[OUTSIDE] = file3.readAll();

    m_temp[KITCHEN] = 20;
    m_temp[BEDROOM1] = 17;
    m_temp[BEDROOM2] = 19;
    m_temp[OUTSIDE] = 35;

    m_curPlace = NOPLACE;
    m_curFunc = NOFUNC;
    m_kitchenButton.click();
}

void EmcDemoWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawImage(0, 0, m_img[m_curImg]);
}

void EmcDemoWidget::sendKeyPress(int keycode)
{
#ifdef Q_WS_QWS
    QWSServer::sendKeyEvent(-1, keycode, 0, true, false);
    QWSServer::sendKeyEvent(-1, keycode, 0, false, false);
#else
    Q_UNUSED(keycode);
#endif
}

void EmcDemoWidget::placeButtonClicked(enum Places place)
{
    if (m_curPlace != NOPLACE)
        m_placeButtons[m_curPlace]->setSelected(false);
    m_curPlace = place;
    m_placeButtons[m_curPlace]->setSelected(true);
    updateView();
}

void EmcDemoWidget::kitchenClicked()
{
    placeButtonClicked(KITCHEN);
}

void EmcDemoWidget::bedRoom1Clicked()
{
    placeButtonClicked(BEDROOM1);
}

void EmcDemoWidget::bedRoom2Clicked()
{
    placeButtonClicked(BEDROOM2);
}

void EmcDemoWidget::outsideClicked()
{
    placeButtonClicked(OUTSIDE);
}

void EmcDemoWidget::updateView()
{
    if (m_curPlace == NOPLACE || m_curFunc == NOFUNC)
        return;

    switch (m_curFunc) {
        case FLOWERS:
            if (m_dlgs[FLOWERS] == NULL)
                m_dlgs[FLOWERS] = new EmcFlowersDlg(this);
            static_cast<EmcFlowersDlg *>(m_dlgs[FLOWERS])->setFlowersCount(
                m_flowersCount[m_curPlace]);
            break;
        case CLOCK:
            if (m_dlgs[CLOCK] == NULL)
                m_dlgs[CLOCK] = new EmcClockDlg(this);
            break;
        case NOTES:
            if (m_dlgs[NOTES] == NULL)
                m_dlgs[NOTES] = new EmcNotesDlg(this);
            static_cast<EmcNotesDlg *>(m_dlgs[NOTES])->setText(
                m_notes[m_curPlace]);
            break;
        case TEMP:
            if (m_dlgs[TEMP] == NULL)
                m_dlgs[TEMP] = new EmcTempDlg(this);
            static_cast<EmcTempDlg *>(m_dlgs[TEMP])->setTemp(
                m_temp[m_curPlace]);
            break;
        default:
            return;
    }
    m_dlgs[m_curFunc]->show();
}

void EmcDemoWidget::changePicture()
{
    if (m_img.size() < 3) {
        m_img.push_back(QImage(QString("pics/backgr_%1.bmp").
                        arg(m_img.size())));
    }
    m_curImg = (m_curImg + 1) % m_img.size();
    repaint();
}

void EmcDemoWidget::funcButtonClicked(enum Funcs func)
{
    if (m_curFunc != NOFUNC) {
        m_dlgs[m_curFunc]->hide();
        m_funcButtons[m_curFunc]->setSelected(false);
    }
    m_curFunc = func;
    m_funcButtons[m_curFunc]->setSelected(true);
    updateView();
}

void EmcDemoWidget::flowersClicked()
{
    funcButtonClicked(FLOWERS);
}

void EmcDemoWidget::clockClicked()
{
    funcButtonClicked(CLOCK);
}

void EmcDemoWidget::notesClicked()
{
    funcButtonClicked(NOTES);
}

void EmcDemoWidget::tempClicked()
{
    funcButtonClicked(TEMP);
}

void EmcDemoWidget::exitClicked()
{
    if (m_curFunc != NOFUNC)
        m_funcButtons[m_curFunc]->setSelected(false);
    m_curFunc = NOFUNC;
}

EmcPicBtn::EmcPicBtn(QWidget *parent, int x, int y, const QString &img) :
    QPushButton(parent),
    m_pressedImg("pics/" + img + "_active.png"),
    m_releasedImg("pics/" + img + ".png"),
    m_checkedImg("pics/" + img + "_checked.png"),
    m_selected(false)
{
    int width = max(m_checkedImg.width(), m_pressedImg.width());
    int height = max(m_checkedImg.height(), m_pressedImg.height());

#ifdef QTDEMO_BORDER_AROUND_FOCUS
    x -= QTDEMO_FOCUS_BORDER_WIDTH;
    y -= QTDEMO_FOCUS_BORDER_WIDTH;
    width += 2 * QTDEMO_FOCUS_BORDER_WIDTH;
    height += 2 * QTDEMO_FOCUS_BORDER_WIDTH;
#endif /* QTDEMO_BORDER_AROUND_FOCUS */

    setGeometry(x, y, width, height);
}   

void EmcPicBtn::paintEvent(QPaintEvent *)
{
    int x = 0, y = 0;
    QPainter p(this);

#ifdef QTDEMO_BORDER_AROUND_FOCUS
    if (hasFocus()) {
        p.setPen(QPen(QBrush(Qt::red), QTDEMO_FOCUS_BORDER_WIDTH));
        p.drawRect(0, 0, width() - 1, height() - 1);
    }

    x = QTDEMO_FOCUS_BORDER_WIDTH;
    y = QTDEMO_FOCUS_BORDER_WIDTH;
#endif /* QTDEMO_BORDER_AROUND_FOCUS */

    p.drawImage(x, y,
                isDown() ? m_pressedImg :
                (m_selected ? m_checkedImg : m_releasedImg));
}

void EmcPicBtn::setSelected(bool enable)
{
    if (m_selected != enable) {
        m_selected = enable;
        repaint();
    }
}

EmcDlg::EmcDlg(QWidget *parent) :
    QWidget(parent),
    m_btnSave(this, 8, 152, "save"),
    m_btnCancel(this, 43, 152, "cancel"),
    m_btnExit(this, 302, 152, "exit")
{
    setGeometry(116, 76, 341, 169);
    hide();

    QObject::connect(&m_btnSave, SIGNAL(clicked()),
                     this, SLOT(saveClicked()));
    QObject::connect(&m_btnCancel, SIGNAL(clicked()),
                     this, SLOT(cancelClicked()));
    QObject::connect(&m_btnExit, SIGNAL(clicked()),
                     this, SLOT(exitClicked()));
    QObject::connect(&m_btnExit, SIGNAL(clicked()),
                     parent, SLOT(exitClicked()));
}

void EmcDlg::keyPressEvent(QKeyEvent *e)
{
    if (!e->modifiers() && e->key() == Qt::Key_Escape)
        m_btnExit.click();
}

EmcFlowersDlg::EmcFlowersDlg(QWidget *parent) :
    EmcDlg(parent),
    m_flowersView(this)
{
    m_flowersView.setGeometry(8, 8, 325, 136);
    m_flowersView.setViewMode(QListView::IconMode);
}

void EmcFlowersDlg::setFlowersCount(unsigned int count)
{
    QIcon icon("pics/plant.png");
    QListWidgetItem item(icon, "Plant 1");
    QFont font(item.font());
    font.setPointSize(6);
    item.setFont(font);

    for (unsigned int i = 0; i < m_items.size(); i++)
        m_flowersView.removeItemWidget(&m_items[i]);
    m_items.clear();

    for (unsigned int i = 0; i < count; i++) {
        item.setText(QString("Plant %1").arg(i + 1, 0, 10));
        m_items.push_back(item);
    }

    for (unsigned int i = 0; i < m_items.size(); i++)
        m_flowersView.addItem(&m_items[i]);
}

EmcClockDlg::EmcClockDlg(QWidget *parent) :
    EmcDlg(parent),
    m_dateEdit(this),
    m_timeEdit(this)
{
    m_time = QTime::currentTime();
    m_date = QDate::currentDate();
    m_dateEdit.setGeometry(126, 38, 96, 22);
    m_dateEdit.setDate(m_date);
    m_timeEdit.setGeometry(126, 86, 96, 22);
    m_timeEdit.setTime(m_time);
}

EmcNotesDlg::EmcNotesDlg(QWidget *parent) :
    EmcDlg(parent),
    m_textWidget(this)
{
    m_textWidget.setGeometry(8, 8, 325, 136);
}

EmcTempDlg::EmcTempDlg(QWidget *parent) :
    EmcDlg(parent),
    m_dial(this),
    m_slider(this)
{
    m_dial.setGeometry(135, 28, 90, 90);
    m_dial.setMinimum(10);
    m_dial.setMaximum(50);
    m_dial.setNotchesVisible(true);
    m_dial.setWrapping(false);
    m_slider.setGeometry(135, 116, 90, 25);
    m_slider.setOrientation(Qt::Horizontal);
    m_slider.setMinimum(10);
    m_slider.setMaximum(50);
    m_slider.setTickInterval(5);
    m_slider.setTickPosition(QSlider::TicksAbove);

    QObject::connect(&m_dial, SIGNAL(valueChanged(int)),
                     this, SLOT(setTemp(int)));
    QObject::connect(&m_slider, SIGNAL(valueChanged(int)),
                     this, SLOT(setTemp(int)));
}

QAtomicInt lock(0);

void EmcDemoThread::run()
{
    unsigned int i = 0;
    enum { SETCURSOR, MOVECURSOR, CLICKBNT, DELAY };
    struct commands_s {
        int cmd;
        int x;
        int y;
        int timeout;
    } cmds[] = {
        { SETCURSOR, 0, 0, 100 },
        { MOVECURSOR, 30, 20, 0 },
        { CLICKBNT, 0, 0, 1000 },
#if MOREAUTO
        { MOVECURSOR, 50, 90, 0 },
        { CLICKBNT, 0, 0, 1000 },

        { MOVECURSOR, 50, 110, 0 },
        { CLICKBNT, 0, 0, 1000 },

        { MOVECURSOR, 50, 130, 0 },
        { CLICKBNT, 0, 0, 1000 },

        { MOVECURSOR, 50, 215, 0 },
        { CLICKBNT, 0, 0, 1000 },
#endif
        { MOVECURSOR, 70, 20, 0 },
        { CLICKBNT, 0, 0, 2000 },
#if MOREAUTO
        { MOVECURSOR, 110, 20, 0 },
        { CLICKBNT, 0, 0, 2000 },

        { MOVECURSOR, 50, 90, 0 },
        { CLICKBNT, 0, 0, 1000 },

        { MOVECURSOR, 50, 110, 0 },
        { CLICKBNT, 0, 0, 1000 },

        { MOVECURSOR, 50, 130, 0 },
        { CLICKBNT, 0, 0, 1000 },

        { MOVECURSOR, 50, 215, 0 },
        { CLICKBNT, 0, 0, 1000 },
#endif
        { MOVECURSOR, 150, 20, 0 },
        { CLICKBNT, 0, 0, 2000 },

        { MOVECURSOR, 440, 20, 0 },
        { CLICKBNT, 0, 0, 2000 },
        { CLICKBNT, 0, 0, 2000 },
        { CLICKBNT, 0, 0, 2000 },
    };
    int x = 0, y = 0;

    while (isRunning()) {
        if (i >= sizeof(cmds) / sizeof(cmds[0]))
            i = 0;
        if (cmds[i].cmd == SETCURSOR || cmds[i].cmd == MOVECURSOR) {
            lock = 1;
            emit moveCursor(cmds[i].x, cmds[i].y);
//            while (!lock.testAndSetAcquire(0, 0)) msleep(10);
            x = cmds[i].x;
            y = cmds[i].y;
        } else if (cmds[i].cmd == MOVECURSOR) {
            if (x != cmds[i].x || y != cmds[i].y) {
                if (x < cmds[i].x) {
                    x++;
                } else if (x > cmds[i].x) {
                    x--;
                }
                if (y < cmds[i].y) {
                    y++;
                } else if (y > cmds[i].y) {
                    y--;
                }
                lock = 1;
                emit moveCursor(x, y);
//                while (!lock.testAndSetAcquire(0, 0)) msleep(10);
                msleep(10);
                continue;
            }
        } else if (cmds[i].cmd == CLICKBNT) {
            lock = 1;
            emit clickMouse();
//            while (!lock.testAndSetAcquire(0, 0)) msleep(10);
        }

        msleep(cmds[i].timeout);
        i++;
    }
}

#ifdef QTDEMO_EMULATE_KEYPRESS_STDIN
void StdInputThread::run()
{
    char str[128];

    while (isRunning()) {
        /*
         * Get a user command
         */
        printf("> ");
        fflush(stdout);
        if (!fgets(str, sizeof(str), stdin))
            break;

        /*
         * Parse the command and perform appripriate action
         */
        switch (str[0]) {
            // Emulate arrow keys
            case 'l': emit sendKeyPress(Qt::Key_Left); break;
            case 'r': emit sendKeyPress(Qt::Key_Right); break;
            case 'u': emit sendKeyPress(Qt::Key_Up); break;
            case 'd': emit sendKeyPress(Qt::Key_Down); break;

            // Let the user push menu buttons by entering 'e'
            case 'e': emit sendKeyPress(Qt::Key_Space); break;
            // Let the user move focus between widgets
            case 't': emit sendKeyPress(Qt::Key_Tab); break;
            // Let the user exit dialogs and go back to the menu
            case 'q': emit sendKeyPress(Qt::Key_Escape); break;

            default:
                printf("Unknown command entered: %s\n", str);
                break;
        }
    }
}
#endif /* QTDEMO_EMULATE_KEYPRESS_STDIN */

int main(int argv, char **args)
{
    S(app);
    QApplication app(argv, args);
    E(app);

    S(win);
    EmcDemoWidget window;
    E(win);

    S(show);
    window.show();
    E(show);

    EmcDemoThread thr(window);

    QObject::connect(&thr, SIGNAL(moveCursor(int, int)),
                     &window, SLOT(moveCursor(int, int)),
                     Qt::BlockingQueuedConnection);//Qt::QueuedConnection);
    QObject::connect(&thr, SIGNAL(clickMouse()),
                     &window, SLOT(clickMouse()),
                     Qt::BlockingQueuedConnection);//Qt::QueuedConnection);

    if (argv > 1)
        thr.start();

#ifdef QTDEMO_EMULATE_KEYPRESS_STDIN
    StdInputThread stdin_thr;
    QObject::connect(&stdin_thr, SIGNAL(sendKeyPress(int)),
                     &window, SLOT(sendKeyPress(int)),
                     Qt::BlockingQueuedConnection);
    stdin_thr.start();
#endif /* QTDEMO_EMULATE_KEYPRESS_STDIN */

    return app.exec();
}
