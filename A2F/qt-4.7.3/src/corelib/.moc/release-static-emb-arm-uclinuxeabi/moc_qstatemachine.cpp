/****************************************************************************
** Meta object code from reading C++ file 'qstatemachine.h'
**
** Created: Wed Dec 16 01:27:24 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../statemachine/qstatemachine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qstatemachine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QStateMachine[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   44, // properties
       1,   50, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      25,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   14,   14,   14, 0x0a,
      43,   14,   14,   14, 0x0a,
      50,   14,   14,   14, 0x08,
      61,   14,   14,   14, 0x08,

 // properties: name, type, flags
      82,   74, 0x0a095001,
     108,   94, 0x0009510b,

 // enums: name, flags, count, data
      94, 0x0,    2,   54,

 // enum data: key, value
     128, uint(QStateMachine::DontRestoreProperties),
     150, uint(QStateMachine::RestoreProperties),

       0        // eod
};

static const char qt_meta_stringdata_QStateMachine[] = {
    "QStateMachine\0\0started()\0stopped()\0"
    "start()\0stop()\0_q_start()\0_q_process()\0"
    "QString\0errorString\0RestorePolicy\0"
    "globalRestorePolicy\0DontRestoreProperties\0"
    "RestoreProperties\0"
};

const QMetaObject QStateMachine::staticMetaObject = {
    { &QState::staticMetaObject, qt_meta_stringdata_QStateMachine,
      qt_meta_data_QStateMachine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QStateMachine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QStateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QStateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QStateMachine))
        return static_cast<void*>(const_cast< QStateMachine*>(this));
    return QState::qt_metacast(_clname);
}

int QStateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QState::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: started(); break;
        case 1: stopped(); break;
        case 2: start(); break;
        case 3: stop(); break;
        case 4: d_func()->_q_start(); break;
        case 5: d_func()->_q_process(); break;
        default: ;
        }
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = errorString(); break;
        case 1: *reinterpret_cast< RestorePolicy*>(_v) = globalRestorePolicy(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setGlobalRestorePolicy(*reinterpret_cast< RestorePolicy*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QStateMachine::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QStateMachine::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
