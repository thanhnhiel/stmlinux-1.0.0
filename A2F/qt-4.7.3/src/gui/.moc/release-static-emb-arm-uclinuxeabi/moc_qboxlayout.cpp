/****************************************************************************
** Meta object code from reading C++ file 'qboxlayout.h'
**
** Created: Wed Dec 16 01:29:29 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kernel/qboxlayout.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qboxlayout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QBoxLayout[] = {

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

static const char qt_meta_stringdata_QBoxLayout[] = {
    "QBoxLayout\0"
};

const QMetaObject QBoxLayout::staticMetaObject = {
    { &QLayout::staticMetaObject, qt_meta_stringdata_QBoxLayout,
      qt_meta_data_QBoxLayout, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QBoxLayout::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QBoxLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QBoxLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QBoxLayout))
        return static_cast<void*>(const_cast< QBoxLayout*>(this));
    return QLayout::qt_metacast(_clname);
}

int QBoxLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QHBoxLayout[] = {

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

static const char qt_meta_stringdata_QHBoxLayout[] = {
    "QHBoxLayout\0"
};

const QMetaObject QHBoxLayout::staticMetaObject = {
    { &QBoxLayout::staticMetaObject, qt_meta_stringdata_QHBoxLayout,
      qt_meta_data_QHBoxLayout, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QHBoxLayout::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QHBoxLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QHBoxLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHBoxLayout))
        return static_cast<void*>(const_cast< QHBoxLayout*>(this));
    return QBoxLayout::qt_metacast(_clname);
}

int QHBoxLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QBoxLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QVBoxLayout[] = {

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

static const char qt_meta_stringdata_QVBoxLayout[] = {
    "QVBoxLayout\0"
};

const QMetaObject QVBoxLayout::staticMetaObject = {
    { &QBoxLayout::staticMetaObject, qt_meta_stringdata_QVBoxLayout,
      qt_meta_data_QVBoxLayout, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QVBoxLayout::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QVBoxLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QVBoxLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QVBoxLayout))
        return static_cast<void*>(const_cast< QVBoxLayout*>(this));
    return QBoxLayout::qt_metacast(_clname);
}

int QVBoxLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QBoxLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
