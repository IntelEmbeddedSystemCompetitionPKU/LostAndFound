/****************************************************************************
** Meta object code from reading C++ file 'platforminputcontext.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../qtvirtualkeyboard/src/virtualkeyboard/platforminputcontext.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'platforminputcontext.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__PlatformInputContext_t {
    QByteArrayData data[5];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__PlatformInputContext_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__PlatformInputContext_t qt_meta_stringdata_QtVirtualKeyboard__PlatformInputContext = {
    {
QT_MOC_LITERAL(0, 0, 39), // "QtVirtualKeyboard::PlatformIn..."
QT_MOC_LITERAL(1, 40, 18), // "focusObjectChanged"
QT_MOC_LITERAL(2, 59, 0), // ""
QT_MOC_LITERAL(3, 60, 24), // "keyboardRectangleChanged"
QT_MOC_LITERAL(4, 85, 23) // "updateInputPanelVisible"

    },
    "QtVirtualKeyboard::PlatformInputContext\0"
    "focusObjectChanged\0\0keyboardRectangleChanged\0"
    "updateInputPanelVisible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__PlatformInputContext[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtVirtualKeyboard::PlatformInputContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlatformInputContext *_t = static_cast<PlatformInputContext *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->focusObjectChanged(); break;
        case 1: _t->keyboardRectangleChanged(); break;
        case 2: _t->updateInputPanelVisible(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PlatformInputContext::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlatformInputContext::focusObjectChanged)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QtVirtualKeyboard::PlatformInputContext::staticMetaObject = {
    { &QPlatformInputContext::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__PlatformInputContext.data,
      qt_meta_data_QtVirtualKeyboard__PlatformInputContext,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::PlatformInputContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::PlatformInputContext::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__PlatformInputContext.stringdata0))
        return static_cast<void*>(this);
    return QPlatformInputContext::qt_metacast(_clname);
}

int QtVirtualKeyboard::PlatformInputContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlatformInputContext::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QtVirtualKeyboard::PlatformInputContext::focusObjectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
