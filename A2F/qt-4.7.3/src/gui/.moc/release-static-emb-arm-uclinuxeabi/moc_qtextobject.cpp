/****************************************************************************
** Meta object code from reading C++ file 'qtextobject.h'
**
** Created: Wed Dec 16 01:29:30 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../text/qtextobject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtextobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QTextObject[] = {

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

static const char qt_meta_stringdata_QTextObject[] = {
    "QTextObject\0"
};

const QMetaObject QTextObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QTextObject,
      qt_meta_data_QTextObject, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QTextObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QTextObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QTextObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTextObject))
        return static_cast<void*>(const_cast< QTextObject*>(this));
    return QObject::qt_metacast(_clname);
}

int QTextObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QTextBlockGroup[] = {

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

static const char qt_meta_stringdata_QTextBlockGroup[] = {
    "QTextBlockGroup\0"
};

const QMetaObject QTextBlockGroup::staticMetaObject = {
    { &QTextObject::staticMetaObject, qt_meta_stringdata_QTextBlockGroup,
      qt_meta_data_QTextBlockGroup, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QTextBlockGroup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QTextBlockGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QTextBlockGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTextBlockGroup))
        return static_cast<void*>(const_cast< QTextBlockGroup*>(this));
    return QTextObject::qt_metacast(_clname);
}

int QTextBlockGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QTextFrame[] = {

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

static const char qt_meta_stringdata_QTextFrame[] = {
    "QTextFrame\0"
};

const QMetaObject QTextFrame::staticMetaObject = {
    { &QTextObject::staticMetaObject, qt_meta_stringdata_QTextFrame,
      qt_meta_data_QTextFrame, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QTextFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QTextFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QTextFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTextFrame))
        return static_cast<void*>(const_cast< QTextFrame*>(this));
    return QTextObject::qt_metacast(_clname);
}

int QTextFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
