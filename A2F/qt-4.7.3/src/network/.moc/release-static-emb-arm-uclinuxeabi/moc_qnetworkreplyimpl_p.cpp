/****************************************************************************
** Meta object code from reading C++ file 'qnetworkreplyimpl_p.h'
**
** Created: Wed Dec 16 01:28:42 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../access/qnetworkreplyimpl_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetworkreplyimpl_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QNetworkReplyImpl[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      39,   18,   18,   18, 0x0a,
      58,   18,   18,   18, 0x0a,
      87,   18,   18,   18, 0x0a,
     111,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QNetworkReplyImpl[] = {
    "QNetworkReplyImpl\0\0_q_startOperation()\0"
    "_q_copyReadyRead()\0_q_copyReadChannelFinished()\0"
    "_q_bufferOutgoingData()\0"
    "_q_bufferOutgoingDataFinished()\0"
};

const QMetaObject QNetworkReplyImpl::staticMetaObject = {
    { &QNetworkReply::staticMetaObject, qt_meta_stringdata_QNetworkReplyImpl,
      qt_meta_data_QNetworkReplyImpl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QNetworkReplyImpl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QNetworkReplyImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QNetworkReplyImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QNetworkReplyImpl))
        return static_cast<void*>(const_cast< QNetworkReplyImpl*>(this));
    return QNetworkReply::qt_metacast(_clname);
}

int QNetworkReplyImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkReply::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: d_func()->_q_startOperation(); break;
        case 1: d_func()->_q_copyReadyRead(); break;
        case 2: d_func()->_q_copyReadChannelFinished(); break;
        case 3: d_func()->_q_bufferOutgoingData(); break;
        case 4: d_func()->_q_bufferOutgoingDataFinished(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
