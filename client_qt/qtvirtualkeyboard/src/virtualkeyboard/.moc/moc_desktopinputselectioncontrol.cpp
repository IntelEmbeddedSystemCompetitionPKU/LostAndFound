/****************************************************************************
** Meta object code from reading C++ file 'desktopinputselectioncontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../desktopinputselectioncontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desktopinputselectioncontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__DesktopInputSelectionControl_t {
    QByteArrayData data[6];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__DesktopInputSelectionControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__DesktopInputSelectionControl_t qt_meta_stringdata_QtVirtualKeyboard__DesktopInputSelectionControl = {
    {
QT_MOC_LITERAL(0, 0, 47), // "QtVirtualKeyboard::DesktopInp..."
QT_MOC_LITERAL(1, 48, 26), // "updateAnchorHandlePosition"
QT_MOC_LITERAL(2, 75, 0), // ""
QT_MOC_LITERAL(3, 76, 26), // "updateCursorHandlePosition"
QT_MOC_LITERAL(4, 103, 16), // "updateVisibility"
QT_MOC_LITERAL(5, 120, 14) // "reloadGraphics"

    },
    "QtVirtualKeyboard::DesktopInputSelectionControl\0"
    "updateAnchorHandlePosition\0\0"
    "updateCursorHandlePosition\0updateVisibility\0"
    "reloadGraphics"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__DesktopInputSelectionControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtVirtualKeyboard::DesktopInputSelectionControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DesktopInputSelectionControl *_t = static_cast<DesktopInputSelectionControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateAnchorHandlePosition(); break;
        case 1: _t->updateCursorHandlePosition(); break;
        case 2: _t->updateVisibility(); break;
        case 3: _t->reloadGraphics(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QtVirtualKeyboard::DesktopInputSelectionControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__DesktopInputSelectionControl.data,
      qt_meta_data_QtVirtualKeyboard__DesktopInputSelectionControl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::DesktopInputSelectionControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::DesktopInputSelectionControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__DesktopInputSelectionControl.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtVirtualKeyboard::DesktopInputSelectionControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
