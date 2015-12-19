/****************************************************************************
** Meta object code from reading C++ file 'qt.h'
**
** Created: Fri Dec 18 01:24:45 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EmcPicBtn[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_EmcPicBtn[] = {
    "EmcPicBtn\0"
};

const QMetaObject EmcPicBtn::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_EmcPicBtn,
      qt_meta_data_EmcPicBtn, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmcPicBtn::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmcPicBtn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmcPicBtn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmcPicBtn))
        return static_cast<void*>(const_cast< EmcPicBtn*>(this));
    return QPushButton::qt_metacast(_clname);
}

int EmcPicBtn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_EmcDlg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x09,
      22,    7,    7,    7, 0x09,
      38,    7,    7,    7, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_EmcDlg[] = {
    "EmcDlg\0\0saveClicked()\0cancelClicked()\0"
    "exitClicked()\0"
};

const QMetaObject EmcDlg::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EmcDlg,
      qt_meta_data_EmcDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmcDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmcDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmcDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmcDlg))
        return static_cast<void*>(const_cast< EmcDlg*>(this));
    return QWidget::qt_metacast(_clname);
}

int EmcDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: saveClicked(); break;
        case 1: cancelClicked(); break;
        case 2: exitClicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_EmcFlowersDlg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_EmcFlowersDlg[] = {
    "EmcFlowersDlg\0"
};

const QMetaObject EmcFlowersDlg::staticMetaObject = {
    { &EmcDlg::staticMetaObject, qt_meta_stringdata_EmcFlowersDlg,
      qt_meta_data_EmcFlowersDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmcFlowersDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmcFlowersDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmcFlowersDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmcFlowersDlg))
        return static_cast<void*>(const_cast< EmcFlowersDlg*>(this));
    return EmcDlg::qt_metacast(_clname);
}

int EmcFlowersDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EmcDlg::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_EmcClockDlg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_EmcClockDlg[] = {
    "EmcClockDlg\0"
};

const QMetaObject EmcClockDlg::staticMetaObject = {
    { &EmcDlg::staticMetaObject, qt_meta_stringdata_EmcClockDlg,
      qt_meta_data_EmcClockDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmcClockDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmcClockDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmcClockDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmcClockDlg))
        return static_cast<void*>(const_cast< EmcClockDlg*>(this));
    return EmcDlg::qt_metacast(_clname);
}

int EmcClockDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EmcDlg::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_EmcNotesDlg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_EmcNotesDlg[] = {
    "EmcNotesDlg\0"
};

const QMetaObject EmcNotesDlg::staticMetaObject = {
    { &EmcDlg::staticMetaObject, qt_meta_stringdata_EmcNotesDlg,
      qt_meta_data_EmcNotesDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmcNotesDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmcNotesDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmcNotesDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmcNotesDlg))
        return static_cast<void*>(const_cast< EmcNotesDlg*>(this));
    return EmcDlg::qt_metacast(_clname);
}

int EmcNotesDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EmcDlg::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_EmcTempDlg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EmcTempDlg[] = {
    "EmcTempDlg\0\0temp\0setTemp(int)\0"
};

const QMetaObject EmcTempDlg::staticMetaObject = {
    { &EmcDlg::staticMetaObject, qt_meta_stringdata_EmcTempDlg,
      qt_meta_data_EmcTempDlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmcTempDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmcTempDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmcTempDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmcTempDlg))
        return static_cast<void*>(const_cast< EmcTempDlg*>(this));
    return EmcDlg::qt_metacast(_clname);
}

int EmcTempDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EmcDlg::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setTemp((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_EmcDemoWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      32,   14,   14,   14, 0x0a,
      50,   14,   14,   14, 0x0a,
      68,   14,   14,   14, 0x0a,
      85,   14,   14,   14, 0x0a,
     101,   14,   14,   14, 0x0a,
     118,   14,   14,   14, 0x0a,
     133,   14,   14,   14, 0x0a,
     148,   14,   14,   14, 0x0a,
     162,   14,   14,   14, 0x0a,
     180,  176,   14,   14, 0x0a,
     200,   14,   14,   14, 0x0a,
     221,  213,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EmcDemoWidget[] = {
    "EmcDemoWidget\0\0kitchenClicked()\0"
    "bedRoom1Clicked()\0bedRoom2Clicked()\0"
    "outsideClicked()\0changePicture()\0"
    "flowersClicked()\0clockClicked()\0"
    "notesClicked()\0tempClicked()\0exitClicked()\0"
    "x,y\0moveCursor(int,int)\0clickMouse()\0"
    "keycode\0sendKeyPress(int)\0"
};

const QMetaObject EmcDemoWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EmcDemoWidget,
      qt_meta_data_EmcDemoWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmcDemoWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmcDemoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmcDemoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmcDemoWidget))
        return static_cast<void*>(const_cast< EmcDemoWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int EmcDemoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: kitchenClicked(); break;
        case 1: bedRoom1Clicked(); break;
        case 2: bedRoom2Clicked(); break;
        case 3: outsideClicked(); break;
        case 4: changePicture(); break;
        case 5: flowersClicked(); break;
        case 6: clockClicked(); break;
        case 7: notesClicked(); break;
        case 8: tempClicked(); break;
        case 9: exitClicked(); break;
        case 10: moveCursor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: clickMouse(); break;
        case 12: sendKeyPress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
static const uint qt_meta_data_EmcDemoThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   15,   14,   14, 0x05,
      37,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_EmcDemoThread[] = {
    "EmcDemoThread\0\0,\0moveCursor(int,int)\0"
    "clickMouse()\0"
};

const QMetaObject EmcDemoThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_EmcDemoThread,
      qt_meta_data_EmcDemoThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EmcDemoThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EmcDemoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EmcDemoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EmcDemoThread))
        return static_cast<void*>(const_cast< EmcDemoThread*>(this));
    return QThread::qt_metacast(_clname);
}

int EmcDemoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: moveCursor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: clickMouse(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void EmcDemoThread::moveCursor(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EmcDemoThread::clickMouse()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
static const uint qt_meta_data_StdInputThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   16,   15,   15, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_StdInputThread[] = {
    "StdInputThread\0\0keycode\0sendKeyPress(int)\0"
};

const QMetaObject StdInputThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_StdInputThread,
      qt_meta_data_StdInputThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StdInputThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StdInputThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StdInputThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StdInputThread))
        return static_cast<void*>(const_cast< StdInputThread*>(this));
    return QThread::qt_metacast(_clname);
}

int StdInputThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendKeyPress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void StdInputThread::sendKeyPress(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
