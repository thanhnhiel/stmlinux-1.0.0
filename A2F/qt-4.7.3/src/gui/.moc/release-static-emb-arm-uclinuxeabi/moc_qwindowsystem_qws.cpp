/****************************************************************************
** Meta object code from reading C++ file 'qwindowsystem_qws.h'
**
** Created: Wed Dec 16 01:29:25 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../embedded/qwindowsystem_qws.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwindowsystem_qws.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QWSServer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   10,   10,   10, 0x08,
      83,   10,   10,   10, 0x08,
     105,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QWSServer[] = {
    "QWSServer\0\0w,e\0"
    "windowEvent(QWSWindow*,QWSServer::WindowEvent)\0"
    "_q_screenSaverWake()\0_q_screenSaverSleep()\0"
    "_q_screenSaverTimeout()\0"
};

const QMetaObject QWSServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QWSServer,
      qt_meta_data_QWSServer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QWSServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QWSServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QWSServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWSServer))
        return static_cast<void*>(const_cast< QWSServer*>(this));
    return QObject::qt_metacast(_clname);
}

int QWSServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: windowEvent((*reinterpret_cast< QWSWindow*(*)>(_a[1])),(*reinterpret_cast< QWSServer::WindowEvent(*)>(_a[2]))); break;
        case 1: d_func()->_q_screenSaverWake(); break;
        case 2: d_func()->_q_screenSaverSleep(); break;
        case 3: d_func()->_q_screenSaverTimeout(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QWSServer::windowEvent(QWSWindow * _t1, QWSServer::WindowEvent _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_QWSClient[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      30,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   10,   10,   10, 0x08,
      57,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QWSClient[] = {
    "QWSClient\0\0connectionClosed()\0readyRead()\0"
    "closeHandler()\0errorHandler()\0"
};

const QMetaObject QWSClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QWSClient,
      qt_meta_data_QWSClient, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QWSClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QWSClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QWSClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWSClient))
        return static_cast<void*>(const_cast< QWSClient*>(this));
    return QObject::qt_metacast(_clname);
}

int QWSClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: connectionClosed(); break;
        case 1: readyRead(); break;
        case 2: closeHandler(); break;
        case 3: errorHandler(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QWSClient::connectionClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QWSClient::readyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
