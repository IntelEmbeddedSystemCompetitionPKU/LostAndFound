/****************************************************************************
** Meta object code from reading C++ file 'shifthandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../qtvirtualkeyboard/src/virtualkeyboard/shifthandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shifthandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__ShiftHandler_t {
    QByteArrayData data[16];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__ShiftHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__ShiftHandler_t qt_meta_stringdata_QtVirtualKeyboard__ShiftHandler = {
    {
QT_MOC_LITERAL(0, 0, 31), // "QtVirtualKeyboard::ShiftHandler"
QT_MOC_LITERAL(1, 32, 31), // "sentenceEndingCharactersChanged"
QT_MOC_LITERAL(2, 64, 0), // ""
QT_MOC_LITERAL(3, 65, 25), // "toggleShiftEnabledChanged"
QT_MOC_LITERAL(4, 91, 32), // "autoCapitalizationEnabledChanged"
QT_MOC_LITERAL(5, 124, 5), // "reset"
QT_MOC_LITERAL(6, 130, 14), // "autoCapitalize"
QT_MOC_LITERAL(7, 145, 7), // "restart"
QT_MOC_LITERAL(8, 153, 13), // "localeChanged"
QT_MOC_LITERAL(9, 167, 12), // "shiftChanged"
QT_MOC_LITERAL(10, 180, 25), // "inputMethodVisibleChanged"
QT_MOC_LITERAL(11, 206, 11), // "toggleShift"
QT_MOC_LITERAL(12, 218, 21), // "clearToggleShiftTimer"
QT_MOC_LITERAL(13, 240, 24), // "sentenceEndingCharacters"
QT_MOC_LITERAL(14, 265, 25), // "autoCapitalizationEnabled"
QT_MOC_LITERAL(15, 291, 18) // "toggleShiftEnabled"

    },
    "QtVirtualKeyboard::ShiftHandler\0"
    "sentenceEndingCharactersChanged\0\0"
    "toggleShiftEnabledChanged\0"
    "autoCapitalizationEnabledChanged\0reset\0"
    "autoCapitalize\0restart\0localeChanged\0"
    "shiftChanged\0inputMethodVisibleChanged\0"
    "toggleShift\0clearToggleShiftTimer\0"
    "sentenceEndingCharacters\0"
    "autoCapitalizationEnabled\0toggleShiftEnabled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__ShiftHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       3,   80, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      11,    0,   78,    2, 0x02 /* Public */,
      12,    0,   79,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      13, QMetaType::QString, 0x00495103,
      14, QMetaType::Bool, 0x00495001,
      15, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       2,
       1,

       0        // eod
};

void QtVirtualKeyboard::ShiftHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShiftHandler *_t = static_cast<ShiftHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sentenceEndingCharactersChanged(); break;
        case 1: _t->toggleShiftEnabledChanged(); break;
        case 2: _t->autoCapitalizationEnabledChanged(); break;
        case 3: _t->reset(); break;
        case 4: _t->autoCapitalize(); break;
        case 5: _t->restart(); break;
        case 6: _t->localeChanged(); break;
        case 7: _t->shiftChanged(); break;
        case 8: _t->inputMethodVisibleChanged(); break;
        case 9: _t->toggleShift(); break;
        case 10: _t->clearToggleShiftTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ShiftHandler::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShiftHandler::sentenceEndingCharactersChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ShiftHandler::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShiftHandler::toggleShiftEnabledChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ShiftHandler::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShiftHandler::autoCapitalizationEnabledChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ShiftHandler *_t = static_cast<ShiftHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->sentenceEndingCharacters(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->autoCapitalizationEnabled(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->toggleShiftEnabled(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ShiftHandler *_t = static_cast<ShiftHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSentenceEndingCharacters(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject QtVirtualKeyboard::ShiftHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__ShiftHandler.data,
      qt_meta_data_QtVirtualKeyboard__ShiftHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::ShiftHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::ShiftHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__ShiftHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtVirtualKeyboard::ShiftHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
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
void QtVirtualKeyboard::ShiftHandler::sentenceEndingCharactersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtVirtualKeyboard::ShiftHandler::toggleShiftEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QtVirtualKeyboard::ShiftHandler::autoCapitalizationEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
