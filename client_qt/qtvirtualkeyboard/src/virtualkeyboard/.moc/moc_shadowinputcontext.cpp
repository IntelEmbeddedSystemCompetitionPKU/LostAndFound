/****************************************************************************
** Meta object code from reading C++ file 'shadowinputcontext.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shadowinputcontext.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shadowinputcontext.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__ShadowInputContext_t {
    QByteArrayData data[18];
    char stringdata0[401];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__ShadowInputContext_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__ShadowInputContext_t qt_meta_stringdata_QtVirtualKeyboard__ShadowInputContext = {
    {
QT_MOC_LITERAL(0, 0, 37), // "QtVirtualKeyboard::ShadowInpu..."
QT_MOC_LITERAL(1, 38, 16), // "inputItemChanged"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 22), // "anchorRectangleChanged"
QT_MOC_LITERAL(4, 79, 22), // "cursorRectangleChanged"
QT_MOC_LITERAL(5, 102, 35), // "anchorRectIntersectsClipRectC..."
QT_MOC_LITERAL(6, 138, 35), // "cursorRectIntersectsClipRectC..."
QT_MOC_LITERAL(7, 174, 30), // "selectionControlVisibleChanged"
QT_MOC_LITERAL(8, 205, 25), // "setSelectionOnFocusObject"
QT_MOC_LITERAL(9, 231, 9), // "anchorPos"
QT_MOC_LITERAL(10, 241, 9), // "cursorPos"
QT_MOC_LITERAL(11, 251, 25), // "updateSelectionProperties"
QT_MOC_LITERAL(12, 277, 9), // "inputItem"
QT_MOC_LITERAL(13, 287, 15), // "anchorRectangle"
QT_MOC_LITERAL(14, 303, 15), // "cursorRectangle"
QT_MOC_LITERAL(15, 319, 28), // "anchorRectIntersectsClipRect"
QT_MOC_LITERAL(16, 348, 28), // "cursorRectIntersectsClipRect"
QT_MOC_LITERAL(17, 377, 23) // "selectionControlVisible"

    },
    "QtVirtualKeyboard::ShadowInputContext\0"
    "inputItemChanged\0\0anchorRectangleChanged\0"
    "cursorRectangleChanged\0"
    "anchorRectIntersectsClipRectChanged\0"
    "cursorRectIntersectsClipRectChanged\0"
    "selectionControlVisibleChanged\0"
    "setSelectionOnFocusObject\0anchorPos\0"
    "cursorPos\0updateSelectionProperties\0"
    "inputItem\0anchorRectangle\0cursorRectangle\0"
    "anchorRectIntersectsClipRect\0"
    "cursorRectIntersectsClipRect\0"
    "selectionControlVisible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__ShadowInputContext[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       6,   66, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    2,   60,    2, 0x02 /* Public */,
      11,    0,   65,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF,    9,   10,
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::QObjectStar, 0x00495103,
      13, QMetaType::QRectF, 0x00495001,
      14, QMetaType::QRectF, 0x00495001,
      15, QMetaType::Bool, 0x00495001,
      16, QMetaType::Bool, 0x00495001,
      17, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,

       0        // eod
};

void QtVirtualKeyboard::ShadowInputContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShadowInputContext *_t = static_cast<ShadowInputContext *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inputItemChanged(); break;
        case 1: _t->anchorRectangleChanged(); break;
        case 2: _t->cursorRectangleChanged(); break;
        case 3: _t->anchorRectIntersectsClipRectChanged(); break;
        case 4: _t->cursorRectIntersectsClipRectChanged(); break;
        case 5: _t->selectionControlVisibleChanged(); break;
        case 6: _t->setSelectionOnFocusObject((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2]))); break;
        case 7: _t->updateSelectionProperties(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ShadowInputContext::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShadowInputContext::inputItemChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ShadowInputContext::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShadowInputContext::anchorRectangleChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ShadowInputContext::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShadowInputContext::cursorRectangleChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ShadowInputContext::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShadowInputContext::anchorRectIntersectsClipRectChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ShadowInputContext::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShadowInputContext::cursorRectIntersectsClipRectChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ShadowInputContext::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShadowInputContext::selectionControlVisibleChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ShadowInputContext *_t = static_cast<ShadowInputContext *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QObject**>(_v) = _t->inputItem(); break;
        case 1: *reinterpret_cast< QRectF*>(_v) = _t->anchorRectangle(); break;
        case 2: *reinterpret_cast< QRectF*>(_v) = _t->cursorRectangle(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->anchorRectIntersectsClipRect(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->cursorRectIntersectsClipRect(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->selectionControlVisible(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ShadowInputContext *_t = static_cast<ShadowInputContext *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setInputItem(*reinterpret_cast< QObject**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QtVirtualKeyboard::ShadowInputContext::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__ShadowInputContext.data,
      qt_meta_data_QtVirtualKeyboard__ShadowInputContext,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::ShadowInputContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::ShadowInputContext::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__ShadowInputContext.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtVirtualKeyboard::ShadowInputContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QtVirtualKeyboard::ShadowInputContext::inputItemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtVirtualKeyboard::ShadowInputContext::anchorRectangleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QtVirtualKeyboard::ShadowInputContext::cursorRectangleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QtVirtualKeyboard::ShadowInputContext::anchorRectIntersectsClipRectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QtVirtualKeyboard::ShadowInputContext::cursorRectIntersectsClipRectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QtVirtualKeyboard::ShadowInputContext::selectionControlVisibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
