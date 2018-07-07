/****************************************************************************
** Meta object code from reading C++ file 'mythread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interact/mythread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mythread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyThread_t {
    QByteArrayData data[17];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyThread_t qt_meta_stringdata_MyThread = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyThread"
QT_MOC_LITERAL(1, 9, 6), // "finish"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 6), // "result"
QT_MOC_LITERAL(4, 24, 10), // "setCommand"
QT_MOC_LITERAL(5, 35, 8), // "_command"
QT_MOC_LITERAL(6, 44, 7), // "setArgs"
QT_MOC_LITERAL(7, 52, 5), // "_args"
QT_MOC_LITERAL(8, 58, 7), // "addDesc"
QT_MOC_LITERAL(9, 66, 4), // "desc"
QT_MOC_LITERAL(10, 71, 7), // "setUUID"
QT_MOC_LITERAL(11, 79, 5), // "_uuid"
QT_MOC_LITERAL(12, 85, 10), // "getNewUUID"
QT_MOC_LITERAL(13, 96, 12), // "startProcess"
QT_MOC_LITERAL(14, 109, 6), // "getDir"
QT_MOC_LITERAL(15, 116, 9), // "processQR"
QT_MOC_LITERAL(16, 126, 5) // "input"

    },
    "MyThread\0finish\0\0result\0setCommand\0"
    "_command\0setArgs\0_args\0addDesc\0desc\0"
    "setUUID\0_uuid\0getNewUUID\0startProcess\0"
    "getDir\0processQR\0input"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    1,   62,    2, 0x02 /* Public */,
       6,    1,   65,    2, 0x02 /* Public */,
       8,    1,   68,    2, 0x02 /* Public */,
      10,    1,   71,    2, 0x02 /* Public */,
      12,    0,   74,    2, 0x02 /* Public */,
      13,    0,   75,    2, 0x02 /* Public */,
      14,    0,   76,    2, 0x02 /* Public */,
      15,    1,   77,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString,   16,

       0        // eod
};

void MyThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyThread *_t = static_cast<MyThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finish((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setArgs((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->addDesc((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setUUID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->getNewUUID(); break;
        case 6: _t->startProcess(); break;
        case 7: { QString _r = _t->getDir();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->processQR((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MyThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThread::finish)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MyThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MyThread.data,
      qt_meta_data_MyThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int MyThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MyThread::finish(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
