/****************************************************************************
** Meta object code from reading C++ file 'enterkeyactionattachedtype.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../enterkeyactionattachedtype.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enterkeyactionattachedtype.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__EnterKeyActionAttachedType_t {
    QByteArrayData data[8];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__EnterKeyActionAttachedType_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__EnterKeyActionAttachedType_t qt_meta_stringdata_QtVirtualKeyboard__EnterKeyActionAttachedType = {
    {
QT_MOC_LITERAL(0, 0, 45), // "QtVirtualKeyboard::EnterKeyAc..."
QT_MOC_LITERAL(1, 46, 15), // "actionIdChanged"
QT_MOC_LITERAL(2, 62, 0), // ""
QT_MOC_LITERAL(3, 63, 12), // "labelChanged"
QT_MOC_LITERAL(4, 76, 14), // "enabledChanged"
QT_MOC_LITERAL(5, 91, 8), // "actionId"
QT_MOC_LITERAL(6, 100, 5), // "label"
QT_MOC_LITERAL(7, 106, 7) // "enabled"

    },
    "QtVirtualKeyboard::EnterKeyActionAttachedType\0"
    "actionIdChanged\0\0labelChanged\0"
    "enabledChanged\0actionId\0label\0enabled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__EnterKeyActionAttachedType[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::Int, 0x00495103,
       6, QMetaType::QString, 0x00495103,
       7, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void QtVirtualKeyboard::EnterKeyActionAttachedType::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EnterKeyActionAttachedType *_t = static_cast<EnterKeyActionAttachedType *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->actionIdChanged(); break;
        case 1: _t->labelChanged(); break;
        case 2: _t->enabledChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (EnterKeyActionAttachedType::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EnterKeyActionAttachedType::actionIdChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (EnterKeyActionAttachedType::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EnterKeyActionAttachedType::labelChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (EnterKeyActionAttachedType::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EnterKeyActionAttachedType::enabledChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        EnterKeyActionAttachedType *_t = static_cast<EnterKeyActionAttachedType *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->actionId(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->label(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->enabled(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        EnterKeyActionAttachedType *_t = static_cast<EnterKeyActionAttachedType *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setActionId(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setLabel(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setEnabled(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject QtVirtualKeyboard::EnterKeyActionAttachedType::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__EnterKeyActionAttachedType.data,
      qt_meta_data_QtVirtualKeyboard__EnterKeyActionAttachedType,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::EnterKeyActionAttachedType::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::EnterKeyActionAttachedType::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__EnterKeyActionAttachedType.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtVirtualKeyboard::EnterKeyActionAttachedType::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QtVirtualKeyboard::EnterKeyActionAttachedType::actionIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtVirtualKeyboard::EnterKeyActionAttachedType::labelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QtVirtualKeyboard::EnterKeyActionAttachedType::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
