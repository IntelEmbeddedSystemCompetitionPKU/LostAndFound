/****************************************************************************
** Meta object code from reading C++ file 'datamanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interact/datamanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datamanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_datamanager_t {
    QByteArrayData data[10];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_datamanager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_datamanager_t qt_meta_stringdata_datamanager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "datamanager"
QT_MOC_LITERAL(1, 12, 7), // "setUUID"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "getDir"
QT_MOC_LITERAL(4, 28, 12), // "processImage"
QT_MOC_LITERAL(5, 41, 14), // "addDescription"
QT_MOC_LITERAL(6, 56, 4), // "desc"
QT_MOC_LITERAL(7, 61, 7), // "isExist"
QT_MOC_LITERAL(8, 69, 4), // "name"
QT_MOC_LITERAL(9, 74, 6) // "popOut"

    },
    "datamanager\0setUUID\0\0getDir\0processImage\0"
    "addDescription\0desc\0isExist\0name\0"
    "popOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_datamanager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x02 /* Public */,
       3,    0,   45,    2, 0x02 /* Public */,
       4,    0,   46,    2, 0x02 /* Public */,
       5,    1,   47,    2, 0x02 /* Public */,
       7,    1,   50,    2, 0x02 /* Public */,
       9,    1,   53,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Bool, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void datamanager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        datamanager *_t = static_cast<datamanager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setUUID(); break;
        case 1: { QString _r = _t->getDir();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->processImage(); break;
        case 3: _t->addDescription((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: { bool _r = _t->isExist((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->popOut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject datamanager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_datamanager.data,
      qt_meta_data_datamanager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *datamanager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *datamanager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_datamanager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int datamanager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
