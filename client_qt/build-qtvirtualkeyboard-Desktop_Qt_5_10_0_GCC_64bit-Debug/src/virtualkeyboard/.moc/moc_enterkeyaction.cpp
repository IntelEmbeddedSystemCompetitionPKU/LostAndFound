/****************************************************************************
** Meta object code from reading C++ file 'enterkeyaction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../qtvirtualkeyboard/src/virtualkeyboard/enterkeyaction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enterkeyaction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__EnterKeyAction_t {
    QByteArrayData data[8];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__EnterKeyAction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__EnterKeyAction_t qt_meta_stringdata_QtVirtualKeyboard__EnterKeyAction = {
    {
QT_MOC_LITERAL(0, 0, 33), // "QtVirtualKeyboard::EnterKeyAc..."
QT_MOC_LITERAL(1, 34, 2), // "Id"
QT_MOC_LITERAL(2, 37, 4), // "None"
QT_MOC_LITERAL(3, 42, 2), // "Go"
QT_MOC_LITERAL(4, 45, 6), // "Search"
QT_MOC_LITERAL(5, 52, 4), // "Send"
QT_MOC_LITERAL(6, 57, 4), // "Next"
QT_MOC_LITERAL(7, 62, 4) // "Done"

    },
    "QtVirtualKeyboard::EnterKeyAction\0Id\0"
    "None\0Go\0Search\0Send\0Next\0Done"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__EnterKeyAction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    6,   18,

 // enum data: key, value
       2, uint(QtVirtualKeyboard::EnterKeyAction::None),
       3, uint(QtVirtualKeyboard::EnterKeyAction::Go),
       4, uint(QtVirtualKeyboard::EnterKeyAction::Search),
       5, uint(QtVirtualKeyboard::EnterKeyAction::Send),
       6, uint(QtVirtualKeyboard::EnterKeyAction::Next),
       7, uint(QtVirtualKeyboard::EnterKeyAction::Done),

       0        // eod
};

void QtVirtualKeyboard::EnterKeyAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QtVirtualKeyboard::EnterKeyAction::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__EnterKeyAction.data,
      qt_meta_data_QtVirtualKeyboard__EnterKeyAction,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::EnterKeyAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::EnterKeyAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__EnterKeyAction.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtVirtualKeyboard::EnterKeyAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
