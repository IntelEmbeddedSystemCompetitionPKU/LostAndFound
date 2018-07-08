/****************************************************************************
** Meta object code from reading C++ file 'trace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../qtvirtualkeyboard/src/virtualkeyboard/trace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__Trace_t {
    QByteArrayData data[22];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__Trace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__Trace_t qt_meta_stringdata_QtVirtualKeyboard__Trace = {
    {
QT_MOC_LITERAL(0, 0, 24), // "QtVirtualKeyboard::Trace"
QT_MOC_LITERAL(1, 25, 14), // "traceIdChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 7), // "traceId"
QT_MOC_LITERAL(4, 49, 15), // "channelsChanged"
QT_MOC_LITERAL(5, 65, 13), // "lengthChanged"
QT_MOC_LITERAL(6, 79, 6), // "length"
QT_MOC_LITERAL(7, 86, 12), // "finalChanged"
QT_MOC_LITERAL(8, 99, 7), // "isFinal"
QT_MOC_LITERAL(9, 107, 15), // "canceledChanged"
QT_MOC_LITERAL(10, 123, 10), // "isCanceled"
QT_MOC_LITERAL(11, 134, 6), // "points"
QT_MOC_LITERAL(12, 141, 3), // "pos"
QT_MOC_LITERAL(13, 145, 5), // "count"
QT_MOC_LITERAL(14, 151, 8), // "addPoint"
QT_MOC_LITERAL(15, 160, 5), // "point"
QT_MOC_LITERAL(16, 166, 14), // "setChannelData"
QT_MOC_LITERAL(17, 181, 7), // "channel"
QT_MOC_LITERAL(18, 189, 5), // "index"
QT_MOC_LITERAL(19, 195, 4), // "data"
QT_MOC_LITERAL(20, 200, 11), // "channelData"
QT_MOC_LITERAL(21, 212, 8) // "channels"

    },
    "QtVirtualKeyboard::Trace\0traceIdChanged\0"
    "\0traceId\0channelsChanged\0lengthChanged\0"
    "length\0finalChanged\0isFinal\0canceledChanged\0"
    "isCanceled\0points\0pos\0count\0addPoint\0"
    "point\0setChannelData\0channel\0index\0"
    "data\0channelData\0channels"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__Trace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       5,  126, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    0,   82,    2, 0x06 /* Public */,
       5,    1,   83,    2, 0x06 /* Public */,
       7,    1,   86,    2, 0x06 /* Public */,
       9,    1,   89,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      11,    2,   92,    2, 0x02 /* Public */,
      11,    1,   97,    2, 0x22 /* Public | MethodCloned */,
      11,    0,  100,    2, 0x22 /* Public | MethodCloned */,
      14,    1,  101,    2, 0x02 /* Public */,
      16,    3,  104,    2, 0x02 /* Public */,
      20,    3,  111,    2, 0x02 /* Public */,
      20,    2,  118,    2, 0x22 /* Public | MethodCloned */,
      20,    1,  123,    2, 0x22 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,   10,

 // methods: parameters
    QMetaType::QVariantList, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::QVariantList, QMetaType::Int,   12,
    QMetaType::QVariantList,
    QMetaType::Int, QMetaType::QPointF,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QVariant,   17,   18,   19,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::Int, QMetaType::Int,   17,   12,   13,
    QMetaType::QVariantList, QMetaType::QString, QMetaType::Int,   17,   12,
    QMetaType::QVariantList, QMetaType::QString,   17,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495103,
      21, QMetaType::QStringList, 0x00495103,
       6, QMetaType::Int, 0x00495001,
       8, QMetaType::Bool, 0x00495003,
      10, QMetaType::Bool, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void QtVirtualKeyboard::Trace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Trace *_t = static_cast<Trace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->traceIdChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->channelsChanged(); break;
        case 2: _t->lengthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->finalChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->canceledChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: { QVariantList _r = _t->points((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariantList _r = _t->points((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 7: { QVariantList _r = _t->points();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->addPoint((*reinterpret_cast< const QPointF(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->setChannelData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3]))); break;
        case 10: { QVariantList _r = _t->channelData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 11: { QVariantList _r = _t->channelData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 12: { QVariantList _r = _t->channelData((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Trace::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trace::traceIdChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Trace::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trace::channelsChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Trace::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trace::lengthChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Trace::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trace::finalChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Trace::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trace::canceledChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Trace *_t = static_cast<Trace *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->traceId(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = _t->channels(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->length(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isFinal(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isCanceled(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Trace *_t = static_cast<Trace *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTraceId(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setChannels(*reinterpret_cast< QStringList*>(_v)); break;
        case 3: _t->setFinal(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setCanceled(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QtVirtualKeyboard::Trace::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__Trace.data,
      qt_meta_data_QtVirtualKeyboard__Trace,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::Trace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::Trace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__Trace.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtVirtualKeyboard::Trace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QtVirtualKeyboard::Trace::traceIdChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtVirtualKeyboard::Trace::channelsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QtVirtualKeyboard::Trace::lengthChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QtVirtualKeyboard::Trace::finalChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QtVirtualKeyboard::Trace::canceledChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
