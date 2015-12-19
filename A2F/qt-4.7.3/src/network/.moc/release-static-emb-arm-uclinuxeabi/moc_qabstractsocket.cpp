/****************************************************************************
** Meta object code from reading C++ file 'qabstractsocket.h'
**
** Created: Wed Dec 16 01:28:42 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../socket/qabstractsocket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QAbstractSocket[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      29,   16,   16,   16, 0x05,
      41,   16,   16,   16, 0x05,
      56,   16,   16,   16, 0x05,
      99,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     154,  135,   16,   16, 0x09,
     222,  208,   16,   16, 0x29,
     267,   16,   16,   16, 0x09,
     302,   16,   16,   16, 0x08,
     328,   16,   16,   16, 0x08,
     358,   16,   16,   16, 0x08,
     386,   16,   16,   16, 0x08,
     406,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QAbstractSocket[] = {
    "QAbstractSocket\0\0hostFound()\0connected()\0"
    "disconnected()\0"
    "stateChanged(QAbstractSocket::SocketState)\0"
    "error(QAbstractSocket::SocketError)\0"
    "hostName,port,mode\0"
    "connectToHostImplementation(QString,quint16,OpenMode)\0"
    "hostName,port\0"
    "connectToHostImplementation(QString,quint16)\0"
    "disconnectFromHostImplementation()\0"
    "_q_connectToNextAddress()\0"
    "_q_startConnecting(QHostInfo)\0"
    "_q_abortConnectionAttempt()\0"
    "_q_testConnection()\0_q_forceDisconnect()\0"
};

const QMetaObject QAbstractSocket::staticMetaObject = {
    { &QIODevice::staticMetaObject, qt_meta_stringdata_QAbstractSocket,
      qt_meta_data_QAbstractSocket, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QAbstractSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QAbstractSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QAbstractSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QAbstractSocket))
        return static_cast<void*>(const_cast< QAbstractSocket*>(this));
    return QIODevice::qt_metacast(_clname);
}

int QAbstractSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: hostFound(); break;
        case 1: connected(); break;
        case 2: disconnected(); break;
        case 3: stateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 4: error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: connectToHostImplementation((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< OpenMode(*)>(_a[3]))); break;
        case 6: connectToHostImplementation((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 7: disconnectFromHostImplementation(); break;
        case 8: d_func()->_q_connectToNextAddress(); break;
        case 9: d_func()->_q_startConnecting((*reinterpret_cast< const QHostInfo(*)>(_a[1]))); break;
        case 10: d_func()->_q_abortConnectionAttempt(); break;
        case 11: d_func()->_q_testConnection(); break;
        case 12: d_func()->_q_forceDisconnect(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void QAbstractSocket::hostFound()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QAbstractSocket::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QAbstractSocket::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QAbstractSocket::stateChanged(QAbstractSocket::SocketState _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QAbstractSocket::error(QAbstractSocket::SocketError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
