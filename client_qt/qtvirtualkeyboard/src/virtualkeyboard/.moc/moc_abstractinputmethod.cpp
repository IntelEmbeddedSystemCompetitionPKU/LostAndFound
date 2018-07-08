/****************************************************************************
** Meta object code from reading C++ file 'abstractinputmethod.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../abstractinputmethod.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abstractinputmethod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__AbstractInputMethod_t {
    QByteArrayData data[9];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__AbstractInputMethod_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__AbstractInputMethod_t qt_meta_stringdata_QtVirtualKeyboard__AbstractInputMethod = {
    {
QT_MOC_LITERAL(0, 0, 38), // "QtVirtualKeyboard::AbstractIn..."
QT_MOC_LITERAL(1, 39, 20), // "selectionListChanged"
QT_MOC_LITERAL(2, 60, 0), // ""
QT_MOC_LITERAL(3, 61, 4), // "type"
QT_MOC_LITERAL(4, 66, 30), // "selectionListActiveItemChanged"
QT_MOC_LITERAL(5, 97, 5), // "index"
QT_MOC_LITERAL(6, 103, 21), // "selectionListsChanged"
QT_MOC_LITERAL(7, 125, 5), // "reset"
QT_MOC_LITERAL(8, 131, 6) // "update"

    },
    "QtVirtualKeyboard::AbstractInputMethod\0"
    "selectionListChanged\0\0type\0"
    "selectionListActiveItemChanged\0index\0"
    "selectionListsChanged\0reset\0update"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__AbstractInputMethod[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    2,   42,    2, 0x06 /* Public */,
       6,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   48,    2, 0x0a /* Public */,
       8,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtVirtualKeyboard::AbstractInputMethod::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractInputMethod *_t = static_cast<AbstractInputMethod *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionListChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->selectionListActiveItemChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->selectionListsChanged(); break;
        case 3: _t->reset(); break;
        case 4: _t->update(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AbstractInputMethod::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractInputMethod::selectionListChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AbstractInputMethod::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractInputMethod::selectionListActiveItemChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AbstractInputMethod::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractInputMethod::selectionListsChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QtVirtualKeyboard::AbstractInputMethod::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__AbstractInputMethod.data,
      qt_meta_data_QtVirtualKeyboard__AbstractInputMethod,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::AbstractInputMethod::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::AbstractInputMethod::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__AbstractInputMethod.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtVirtualKeyboard::AbstractInputMethod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QtVirtualKeyboard::AbstractInputMethod::selectionListChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtVirtualKeyboard::AbstractInputMethod::selectionListActiveItemChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtVirtualKeyboard::AbstractInputMethod::selectionListsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
