/****************************************************************************
** Meta object code from reading C++ file 'qgraphicswidget.h'
**
** Created: Wed Dec 16 01:29:34 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../graphicsview/qgraphicswidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgraphicswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QGraphicsWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
      14,   29, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      35,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   16,   51,   16, 0x0a,

 // properties: name, type, flags
      73,   64, 0x44095103,
      87,   81, 0x40095103,
     112,   92, 0x0009510f,
     135,  128, 0x16495003,
     140,  128, 0x16095103,
     152,  128, 0x16095103,
     166,  128, 0x16095103,
     190,  178, 0x4b095103,
     217,  201, 0x0009510b,
     245,  229, 0x0009510b,
     265,  257, 0x0a095103,
     284,  277, 0x14495103,
     293,   51, 0x01095103,
     329,  312, 0x0049510b,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_QGraphicsWidget[] = {
    "QGraphicsWidget\0\0geometryChanged()\0"
    "layoutChanged()\0bool\0close()\0QPalette\0"
    "palette\0QFont\0font\0Qt::LayoutDirection\0"
    "layoutDirection\0QSizeF\0size\0minimumSize\0"
    "preferredSize\0maximumSize\0QSizePolicy\0"
    "sizePolicy\0Qt::FocusPolicy\0focusPolicy\0"
    "Qt::WindowFlags\0windowFlags\0QString\0"
    "windowTitle\0QRectF\0geometry\0"
    "autoFillBackground\0QGraphicsLayout*\0"
    "layout\0"
};

const QMetaObject QGraphicsWidget::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_QGraphicsWidget,
      qt_meta_data_QGraphicsWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QGraphicsWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QGraphicsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QGraphicsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QGraphicsWidget))
        return static_cast<void*>(const_cast< QGraphicsWidget*>(this));
    if (!strcmp(_clname, "QGraphicsLayoutItem"))
        return static_cast< QGraphicsLayoutItem*>(const_cast< QGraphicsWidget*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< QGraphicsWidget*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.QGraphicsLayoutItem"))
        return static_cast< QGraphicsLayoutItem*>(const_cast< QGraphicsWidget*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int QGraphicsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: geometryChanged(); break;
        case 1: layoutChanged(); break;
        case 2: { bool _r = close();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPalette*>(_v) = palette(); break;
        case 1: *reinterpret_cast< QFont*>(_v) = font(); break;
        case 2: *reinterpret_cast< Qt::LayoutDirection*>(_v) = layoutDirection(); break;
        case 3: *reinterpret_cast< QSizeF*>(_v) = size(); break;
        case 4: *reinterpret_cast< QSizeF*>(_v) = minimumSize(); break;
        case 5: *reinterpret_cast< QSizeF*>(_v) = preferredSize(); break;
        case 6: *reinterpret_cast< QSizeF*>(_v) = maximumSize(); break;
        case 7: *reinterpret_cast< QSizePolicy*>(_v) = sizePolicy(); break;
        case 8: *reinterpret_cast< Qt::FocusPolicy*>(_v) = focusPolicy(); break;
        case 9: *reinterpret_cast< Qt::WindowFlags*>(_v) = windowFlags(); break;
        case 10: *reinterpret_cast< QString*>(_v) = windowTitle(); break;
        case 11: *reinterpret_cast< QRectF*>(_v) = geometry(); break;
        case 12: *reinterpret_cast< bool*>(_v) = autoFillBackground(); break;
        case 13: *reinterpret_cast< QGraphicsLayout**>(_v) = layout(); break;
        }
        _id -= 14;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setPalette(*reinterpret_cast< QPalette*>(_v)); break;
        case 1: setFont(*reinterpret_cast< QFont*>(_v)); break;
        case 2: setLayoutDirection(*reinterpret_cast< Qt::LayoutDirection*>(_v)); break;
        case 3: resize(*reinterpret_cast< QSizeF*>(_v)); break;
        case 4: setMinimumSize(*reinterpret_cast< QSizeF*>(_v)); break;
        case 5: setPreferredSize(*reinterpret_cast< QSizeF*>(_v)); break;
        case 6: setMaximumSize(*reinterpret_cast< QSizeF*>(_v)); break;
        case 7: setSizePolicy(*reinterpret_cast< QSizePolicy*>(_v)); break;
        case 8: setFocusPolicy(*reinterpret_cast< Qt::FocusPolicy*>(_v)); break;
        case 9: setWindowFlags(*reinterpret_cast< Qt::WindowFlags*>(_v)); break;
        case 10: setWindowTitle(*reinterpret_cast< QString*>(_v)); break;
        case 11: setGeometry(*reinterpret_cast< QRectF*>(_v)); break;
        case 12: setAutoFillBackground(*reinterpret_cast< bool*>(_v)); break;
        case 13: setLayout(*reinterpret_cast< QGraphicsLayout**>(_v)); break;
        }
        _id -= 14;
    } else if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 2: unsetLayoutDirection(); break;
        }
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 14;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 14;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QGraphicsWidget::geometryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QGraphicsWidget::layoutChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
