/****************************************************************************
** Meta object code from reading C++ file 'qtextcontrol_p.h'
**
** Created: Wed Dec 16 01:29:26 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../text/qtextcontrol_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtextcontrol_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QTextControl[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       7,  184, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      30,   28,   13,   13, 0x05,
      50,   28,   13,   13, 0x05,
      77,   70,   13,   13, 0x05,
     119,   28,   13,   13, 0x05,
     139,   13,   13,   13, 0x05,
     158,   13,   13,   13, 0x05,
     187,  182,   13,   13, 0x05,
     209,   13,   13,   13, 0x25,
     225,   13,   13,   13, 0x05,
     267,  253,   13,   13, 0x05,
     290,  182,   13,   13, 0x05,
     316,   13,   13,   13, 0x05,
     341,  336,   13,   13, 0x05,
     364,   13,   13,   13, 0x05,
     387,  385,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     418,  413,   13,   13, 0x0a,
     440,  413,   13,   13, 0x0a,
     457,   13,   13,   13, 0x0a,
     464,   13,   13,   13, 0x0a,
     471,   13,   13,   13, 0x0a,
     479,   13,   13,   13, 0x0a,
     491,  413,   13,   13, 0x0a,
     516,  413,   13,   13, 0x0a,
     536,  413,   13,   13, 0x0a,
     557,  552,   13,   13, 0x0a,
     577,  413,   13,   13, 0x0a,
     602,   13,   13,   13, 0x0a,
     615,   13,   13,   13, 0x08,
     656,   13,   13,   13, 0x08,
     693,   13,   13,   13, 0x08,
     713,   13,   13,   13, 0x08,
     727,   13,   13,   13, 0x08,
     754,   13,   13,   13, 0x08,

 // properties: name, type, flags
     552,  781, 0x0a595103,
     794,  789, 0x01095103,
     808,  789, 0x01095103,
     827,  823, 0x02095103,
     864,  839, 0x0009510b,
     885,  789, 0x01095103,
     903,  789, 0x01095103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_QTextControl[] = {
    "QTextControl\0\0textChanged()\0b\0"
    "undoAvailable(bool)\0redoAvailable(bool)\0"
    "format\0currentCharFormatChanged(QTextCharFormat)\0"
    "copyAvailable(bool)\0selectionChanged()\0"
    "cursorPositionChanged()\0rect\0"
    "updateRequest(QRectF)\0updateRequest()\0"
    "documentSizeChanged(QSizeF)\0newBlockCount\0"
    "blockCountChanged(int)\0visibilityRequest(QRectF)\0"
    "microFocusChanged()\0link\0"
    "linkActivated(QString)\0linkHovered(QString)\0"
    "m\0modificationChanged(bool)\0text\0"
    "setPlainText(QString)\0setHtml(QString)\0"
    "undo()\0redo()\0clear()\0selectAll()\0"
    "insertPlainText(QString)\0insertHtml(QString)\0"
    "append(QString)\0html\0appendHtml(QString)\0"
    "appendPlainText(QString)\0adjustSize()\0"
    "_q_updateCurrentCharFormatAndSelection()\0"
    "_q_emitCursorPosChanged(QTextCursor)\0"
    "_q_deleteSelected()\0_q_copyLink()\0"
    "_q_updateBlock(QTextBlock)\0"
    "_q_documentLayoutChanged()\0QString\0"
    "bool\0overwriteMode\0acceptRichText\0int\0"
    "cursorWidth\0Qt::TextInteractionFlags\0"
    "textInteractionFlags\0openExternalLinks\0"
    "ignoreUnusedNavigationEvents\0"
};

const QMetaObject QTextControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QTextControl,
      qt_meta_data_QTextControl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QTextControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QTextControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QTextControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTextControl))
        return static_cast<void*>(const_cast< QTextControl*>(this));
    return QObject::qt_metacast(_clname);
}

int QTextControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: textChanged(); break;
        case 1: undoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: redoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: currentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 4: copyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: selectionChanged(); break;
        case 6: cursorPositionChanged(); break;
        case 7: updateRequest((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 8: updateRequest(); break;
        case 9: documentSizeChanged((*reinterpret_cast< const QSizeF(*)>(_a[1]))); break;
        case 10: blockCountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: visibilityRequest((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 12: microFocusChanged(); break;
        case 13: linkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: linkHovered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: modificationChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: setPlainText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: setHtml((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: undo(); break;
        case 19: redo(); break;
        case 20: clear(); break;
        case 21: selectAll(); break;
        case 22: insertPlainText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: insertHtml((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: append((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 25: appendHtml((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: appendPlainText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: adjustSize(); break;
        case 28: d_func()->_q_updateCurrentCharFormatAndSelection(); break;
        case 29: d_func()->_q_emitCursorPosChanged((*reinterpret_cast< const QTextCursor(*)>(_a[1]))); break;
        case 30: d_func()->_q_deleteSelected(); break;
        case 31: d_func()->_q_copyLink(); break;
        case 32: d_func()->_q_updateBlock((*reinterpret_cast< const QTextBlock(*)>(_a[1]))); break;
        case 33: d_func()->_q_documentLayoutChanged(); break;
        default: ;
        }
        _id -= 34;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = toHtml(); break;
        case 1: *reinterpret_cast< bool*>(_v) = overwriteMode(); break;
        case 2: *reinterpret_cast< bool*>(_v) = acceptRichText(); break;
        case 3: *reinterpret_cast< int*>(_v) = cursorWidth(); break;
        case 4: *reinterpret_cast< Qt::TextInteractionFlags*>(_v) = textInteractionFlags(); break;
        case 5: *reinterpret_cast< bool*>(_v) = openExternalLinks(); break;
        case 6: *reinterpret_cast< bool*>(_v) = ignoreUnusedNavigationEvents(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setHtml(*reinterpret_cast< QString*>(_v)); break;
        case 1: setOverwriteMode(*reinterpret_cast< bool*>(_v)); break;
        case 2: setAcceptRichText(*reinterpret_cast< bool*>(_v)); break;
        case 3: setCursorWidth(*reinterpret_cast< int*>(_v)); break;
        case 4: setTextInteractionFlags(*reinterpret_cast< Qt::TextInteractionFlags*>(_v)); break;
        case 5: setOpenExternalLinks(*reinterpret_cast< bool*>(_v)); break;
        case 6: setIgnoreUnusedNavigationEvents(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QTextControl::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QTextControl::undoAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QTextControl::redoAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QTextControl::currentCharFormatChanged(const QTextCharFormat & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QTextControl::copyAvailable(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QTextControl::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void QTextControl::cursorPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void QTextControl::updateRequest(const QRectF & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 9
void QTextControl::documentSizeChanged(const QSizeF & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void QTextControl::blockCountChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void QTextControl::visibilityRequest(const QRectF & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QTextControl::microFocusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void QTextControl::linkActivated(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void QTextControl::linkHovered(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void QTextControl::modificationChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
static const uint qt_meta_data_QUnicodeControlCharacterMenu[] = {

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
      30,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QUnicodeControlCharacterMenu[] = {
    "QUnicodeControlCharacterMenu\0\0"
    "menuActionTriggered()\0"
};

const QMetaObject QUnicodeControlCharacterMenu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_QUnicodeControlCharacterMenu,
      qt_meta_data_QUnicodeControlCharacterMenu, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QUnicodeControlCharacterMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QUnicodeControlCharacterMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QUnicodeControlCharacterMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QUnicodeControlCharacterMenu))
        return static_cast<void*>(const_cast< QUnicodeControlCharacterMenu*>(this));
    return QMenu::qt_metacast(_clname);
}

int QUnicodeControlCharacterMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: menuActionTriggered(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
