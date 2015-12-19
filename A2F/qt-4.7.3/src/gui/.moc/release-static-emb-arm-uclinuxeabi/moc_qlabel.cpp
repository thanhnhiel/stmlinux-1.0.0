/****************************************************************************
** Meta object code from reading C++ file 'qlabel.h'
**
** Created: Wed Dec 16 01:29:26 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widgets/qlabel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QLabel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
      12,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,    8,    7,    7, 0x05,
      36,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,    7,    7,    7, 0x0a,
      74,    7,    7,    7, 0x0a,
      93,    7,    7,    7, 0x0a,
     105,    7,    7,    7, 0x0a,
     120,    7,    7,    7, 0x0a,
     128,    7,    7,    7, 0x08,

 // properties: name, type, flags
     160,  152, 0x0a095103,
     180,  165, 0x0009510b,
     199,  191, 0x41095103,
     211,  206, 0x01095103,
     240,  226, 0x0009510b,
     250,  206, 0x01095103,
     263,  259, 0x02095103,
     270,  259, 0x02095103,
     277,  206, 0x01095103,
     320,  295, 0x0009510b,
     341,  206, 0x01095001,
     357,  152, 0x0a095001,

       0        // eod
};

static const char qt_meta_stringdata_QLabel[] = {
    "QLabel\0\0link\0linkActivated(QString)\0"
    "linkHovered(QString)\0setText(QString)\0"
    "setPixmap(QPixmap)\0setNum(int)\0"
    "setNum(double)\0clear()\0_q_linkHovered(QString)\0"
    "QString\0text\0Qt::TextFormat\0textFormat\0"
    "QPixmap\0pixmap\0bool\0scaledContents\0"
    "Qt::Alignment\0alignment\0wordWrap\0int\0"
    "margin\0indent\0openExternalLinks\0"
    "Qt::TextInteractionFlags\0textInteractionFlags\0"
    "hasSelectedText\0selectedText\0"
};

const QMetaObject QLabel::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_QLabel,
      qt_meta_data_QLabel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QLabel))
        return static_cast<void*>(const_cast< QLabel*>(this));
    return QFrame::qt_metacast(_clname);
}

int QLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: linkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: linkHovered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: setPixmap((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 4: setNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: setNum((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: clear(); break;
        case 7: d_func()->_q_linkHovered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = text(); break;
        case 1: *reinterpret_cast< Qt::TextFormat*>(_v) = textFormat(); break;
        case 2: _a[0] = const_cast<void*>(reinterpret_cast<const void*>(pixmap())); break;
        case 3: *reinterpret_cast< bool*>(_v) = hasScaledContents(); break;
        case 4: *reinterpret_cast< Qt::Alignment*>(_v) = alignment(); break;
        case 5: *reinterpret_cast< bool*>(_v) = wordWrap(); break;
        case 6: *reinterpret_cast< int*>(_v) = margin(); break;
        case 7: *reinterpret_cast< int*>(_v) = indent(); break;
        case 8: *reinterpret_cast< bool*>(_v) = openExternalLinks(); break;
        case 9: *reinterpret_cast< Qt::TextInteractionFlags*>(_v) = textInteractionFlags(); break;
        case 10: *reinterpret_cast< bool*>(_v) = hasSelectedText(); break;
        case 11: *reinterpret_cast< QString*>(_v) = selectedText(); break;
        }
        _id -= 12;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setText(*reinterpret_cast< QString*>(_v)); break;
        case 1: setTextFormat(*reinterpret_cast< Qt::TextFormat*>(_v)); break;
        case 2: setPixmap(*reinterpret_cast< QPixmap*>(_v)); break;
        case 3: setScaledContents(*reinterpret_cast< bool*>(_v)); break;
        case 4: setAlignment(*reinterpret_cast< Qt::Alignment*>(_v)); break;
        case 5: setWordWrap(*reinterpret_cast< bool*>(_v)); break;
        case 6: setMargin(*reinterpret_cast< int*>(_v)); break;
        case 7: setIndent(*reinterpret_cast< int*>(_v)); break;
        case 8: setOpenExternalLinks(*reinterpret_cast< bool*>(_v)); break;
        case 9: setTextInteractionFlags(*reinterpret_cast< Qt::TextInteractionFlags*>(_v)); break;
        }
        _id -= 12;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 12;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QLabel::linkActivated(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QLabel::linkHovered(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
