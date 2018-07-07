/****************************************************************************
** Meta object code from reading C++ file 'desktopinputpanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../desktopinputpanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desktopinputpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__DesktopInputPanel_t {
    QByteArrayData data[13];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__DesktopInputPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__DesktopInputPanel_t qt_meta_stringdata_QtVirtualKeyboard__DesktopInputPanel = {
    {
QT_MOC_LITERAL(0, 0, 36), // "QtVirtualKeyboard::DesktopInp..."
QT_MOC_LITERAL(1, 37, 10), // "createView"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 11), // "destroyView"
QT_MOC_LITERAL(4, 61, 14), // "repositionView"
QT_MOC_LITERAL(5, 76, 4), // "rect"
QT_MOC_LITERAL(6, 81, 18), // "focusWindowChanged"
QT_MOC_LITERAL(7, 100, 8), // "QWindow*"
QT_MOC_LITERAL(8, 109, 11), // "focusWindow"
QT_MOC_LITERAL(9, 121, 25), // "focusWindowVisibleChanged"
QT_MOC_LITERAL(10, 147, 7), // "visible"
QT_MOC_LITERAL(11, 155, 23), // "previewRectangleChanged"
QT_MOC_LITERAL(12, 179, 21) // "previewVisibleChanged"

    },
    "QtVirtualKeyboard::DesktopInputPanel\0"
    "createView\0\0destroyView\0repositionView\0"
    "rect\0focusWindowChanged\0QWindow*\0"
    "focusWindow\0focusWindowVisibleChanged\0"
    "visible\0previewRectangleChanged\0"
    "previewVisibleChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__DesktopInputPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    1,   51,    2, 0x09 /* Protected */,
       6,    1,   54,    2, 0x09 /* Protected */,
       9,    1,   57,    2, 0x09 /* Protected */,
      11,    0,   60,    2, 0x09 /* Protected */,
      12,    0,   61,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRect,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtVirtualKeyboard::DesktopInputPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DesktopInputPanel *_t = static_cast<DesktopInputPanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createView(); break;
        case 1: _t->destroyView(); break;
        case 2: _t->repositionView((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 3: _t->focusWindowChanged((*reinterpret_cast< QWindow*(*)>(_a[1]))); break;
        case 4: _t->focusWindowVisibleChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->previewRectangleChanged(); break;
        case 6: _t->previewVisibleChanged(); break;
        default: ;
        }
    }
}

const QMetaObject QtVirtualKeyboard::DesktopInputPanel::staticMetaObject = {
    { &AppInputPanel::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__DesktopInputPanel.data,
      qt_meta_data_QtVirtualKeyboard__DesktopInputPanel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::DesktopInputPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::DesktopInputPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__DesktopInputPanel.stringdata0))
        return static_cast<void*>(this);
    return AppInputPanel::qt_metacast(_clname);
}

int QtVirtualKeyboard::DesktopInputPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AppInputPanel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
