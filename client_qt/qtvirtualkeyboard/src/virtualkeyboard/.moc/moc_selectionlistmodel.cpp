/****************************************************************************
** Meta object code from reading C++ file 'selectionlistmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../selectionlistmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectionlistmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__SelectionListModel_t {
    QByteArrayData data[18];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__SelectionListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__SelectionListModel_t qt_meta_stringdata_QtVirtualKeyboard__SelectionListModel = {
    {
QT_MOC_LITERAL(0, 0, 37), // "QtVirtualKeyboard::SelectionL..."
QT_MOC_LITERAL(1, 38, 12), // "countChanged"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 17), // "activeItemChanged"
QT_MOC_LITERAL(4, 70, 5), // "index"
QT_MOC_LITERAL(5, 76, 12), // "itemSelected"
QT_MOC_LITERAL(6, 89, 20), // "selectionListChanged"
QT_MOC_LITERAL(7, 110, 4), // "type"
QT_MOC_LITERAL(8, 115, 30), // "selectionListActiveItemChanged"
QT_MOC_LITERAL(9, 146, 10), // "selectItem"
QT_MOC_LITERAL(10, 157, 6), // "dataAt"
QT_MOC_LITERAL(11, 164, 4), // "role"
QT_MOC_LITERAL(12, 169, 5), // "count"
QT_MOC_LITERAL(13, 175, 4), // "Type"
QT_MOC_LITERAL(14, 180, 17), // "WordCandidateList"
QT_MOC_LITERAL(15, 198, 4), // "Role"
QT_MOC_LITERAL(16, 203, 11), // "DisplayRole"
QT_MOC_LITERAL(17, 215, 24) // "WordCompletionLengthRole"

    },
    "QtVirtualKeyboard::SelectionListModel\0"
    "countChanged\0\0activeItemChanged\0index\0"
    "itemSelected\0selectionListChanged\0"
    "type\0selectionListActiveItemChanged\0"
    "selectItem\0dataAt\0role\0count\0Type\0"
    "WordCandidateList\0Role\0DisplayRole\0"
    "WordCompletionLengthRole"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__SelectionListModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       1,   80, // properties
       2,   84, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   61,    2, 0x09 /* Protected */,
       8,    2,   64,    2, 0x09 /* Protected */,

 // methods: name, argc, parameters, tag, flags
       9,    1,   69,    2, 0x02 /* Public */,
      10,    2,   72,    2, 0x02 /* Public */,
      10,    1,   77,    2, 0x22 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    4,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::QVariant, QMetaType::Int, QMetaType::Int,    4,   11,
    QMetaType::QVariant, QMetaType::Int,    4,

 // properties: name, type, flags
      12, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       0,

 // enums: name, flags, count, data
      13, 0x0,    1,   92,
      15, 0x0,    2,   94,

 // enum data: key, value
      14, uint(QtVirtualKeyboard::SelectionListModel::WordCandidateList),
      16, uint(QtVirtualKeyboard::SelectionListModel::DisplayRole),
      17, uint(QtVirtualKeyboard::SelectionListModel::WordCompletionLengthRole),

       0        // eod
};

void QtVirtualKeyboard::SelectionListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectionListModel *_t = static_cast<SelectionListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->countChanged(); break;
        case 1: _t->activeItemChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->itemSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->selectionListChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->selectionListActiveItemChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->selectItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: { QVariant _r = _t->dataAt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 7: { QVariant _r = _t->dataAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SelectionListModel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelectionListModel::countChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SelectionListModel::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelectionListModel::activeItemChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SelectionListModel::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelectionListModel::itemSelected)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        SelectionListModel *_t = static_cast<SelectionListModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->count(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QtVirtualKeyboard::SelectionListModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__SelectionListModel.data,
      qt_meta_data_QtVirtualKeyboard__SelectionListModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::SelectionListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::SelectionListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__SelectionListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int QtVirtualKeyboard::SelectionListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
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
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QtVirtualKeyboard::SelectionListModel::countChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtVirtualKeyboard::SelectionListModel::activeItemChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtVirtualKeyboard::SelectionListModel::itemSelected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
