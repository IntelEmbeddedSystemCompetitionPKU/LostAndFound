/****************************************************************************
** Meta object code from reading C++ file 'virtualkeyboardsettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../qtvirtualkeyboard/src/virtualkeyboard/virtualkeyboardsettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'virtualkeyboardsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__VirtualKeyboardSettings_t {
    QByteArrayData data[18];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__VirtualKeyboardSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__VirtualKeyboardSettings_t qt_meta_stringdata_QtVirtualKeyboard__VirtualKeyboardSettings = {
    {
QT_MOC_LITERAL(0, 0, 42), // "QtVirtualKeyboard::VirtualKey..."
QT_MOC_LITERAL(1, 43, 12), // "styleChanged"
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 16), // "styleNameChanged"
QT_MOC_LITERAL(4, 74, 13), // "localeChanged"
QT_MOC_LITERAL(5, 88, 23), // "availableLocalesChanged"
QT_MOC_LITERAL(6, 112, 20), // "activeLocalesChanged"
QT_MOC_LITERAL(7, 133, 17), // "layoutPathChanged"
QT_MOC_LITERAL(8, 151, 21), // "fullScreenModeChanged"
QT_MOC_LITERAL(9, 173, 5), // "style"
QT_MOC_LITERAL(10, 179, 10), // "layoutPath"
QT_MOC_LITERAL(11, 190, 9), // "styleName"
QT_MOC_LITERAL(12, 200, 6), // "locale"
QT_MOC_LITERAL(13, 207, 16), // "availableLocales"
QT_MOC_LITERAL(14, 224, 13), // "activeLocales"
QT_MOC_LITERAL(15, 238, 17), // "wordCandidateList"
QT_MOC_LITERAL(16, 256, 26), // "WordCandidateListSettings*"
QT_MOC_LITERAL(17, 283, 14) // "fullScreenMode"

    },
    "QtVirtualKeyboard::VirtualKeyboardSettings\0"
    "styleChanged\0\0styleNameChanged\0"
    "localeChanged\0availableLocalesChanged\0"
    "activeLocalesChanged\0layoutPathChanged\0"
    "fullScreenModeChanged\0style\0layoutPath\0"
    "styleName\0locale\0availableLocales\0"
    "activeLocales\0wordCandidateList\0"
    "WordCandidateListSettings*\0fullScreenMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__VirtualKeyboardSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       8,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    0,   54,    2, 0x06 /* Public */,
       8,    0,   55,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::QUrl, 0x00495001,
      10, QMetaType::QUrl, 0x00495103,
      11, QMetaType::QString, 0x00495103,
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::QStringList, 0x00495001,
      14, QMetaType::QStringList, 0x00495103,
      15, 0x80000000 | 16, 0x00095409,
      17, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       5,
       1,
       2,
       3,
       4,
       0,
       6,

       0        // eod
};

void QtVirtualKeyboard::VirtualKeyboardSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VirtualKeyboardSettings *_t = static_cast<VirtualKeyboardSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->styleChanged(); break;
        case 1: _t->styleNameChanged(); break;
        case 2: _t->localeChanged(); break;
        case 3: _t->availableLocalesChanged(); break;
        case 4: _t->activeLocalesChanged(); break;
        case 5: _t->layoutPathChanged(); break;
        case 6: _t->fullScreenModeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (VirtualKeyboardSettings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VirtualKeyboardSettings::styleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (VirtualKeyboardSettings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VirtualKeyboardSettings::styleNameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (VirtualKeyboardSettings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VirtualKeyboardSettings::localeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (VirtualKeyboardSettings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VirtualKeyboardSettings::availableLocalesChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (VirtualKeyboardSettings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VirtualKeyboardSettings::activeLocalesChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (VirtualKeyboardSettings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VirtualKeyboardSettings::layoutPathChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (VirtualKeyboardSettings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VirtualKeyboardSettings::fullScreenModeChanged)) {
                *result = 6;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WordCandidateListSettings* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        VirtualKeyboardSettings *_t = static_cast<VirtualKeyboardSettings *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QUrl*>(_v) = _t->style(); break;
        case 1: *reinterpret_cast< QUrl*>(_v) = _t->layoutPath(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->styleName(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->locale(); break;
        case 4: *reinterpret_cast< QStringList*>(_v) = _t->availableLocales(); break;
        case 5: *reinterpret_cast< QStringList*>(_v) = _t->activeLocales(); break;
        case 6: *reinterpret_cast< WordCandidateListSettings**>(_v) = _t->wordCandidateList(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->fullScreenMode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        VirtualKeyboardSettings *_t = static_cast<VirtualKeyboardSettings *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setLayoutPath(*reinterpret_cast< QUrl*>(_v)); break;
        case 2: _t->setStyleName(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setLocale(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setActiveLocales(*reinterpret_cast< QStringList*>(_v)); break;
        case 7: _t->setFullScreenMode(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QtVirtualKeyboard::VirtualKeyboardSettings::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__VirtualKeyboardSettings.data,
      qt_meta_data_QtVirtualKeyboard__VirtualKeyboardSettings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::VirtualKeyboardSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::VirtualKeyboardSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__VirtualKeyboardSettings.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtVirtualKeyboard::VirtualKeyboardSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QtVirtualKeyboard::VirtualKeyboardSettings::styleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtVirtualKeyboard::VirtualKeyboardSettings::styleNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QtVirtualKeyboard::VirtualKeyboardSettings::localeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QtVirtualKeyboard::VirtualKeyboardSettings::availableLocalesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QtVirtualKeyboard::VirtualKeyboardSettings::activeLocalesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QtVirtualKeyboard::VirtualKeyboardSettings::layoutPathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QtVirtualKeyboard::VirtualKeyboardSettings::fullScreenModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
struct qt_meta_stringdata_QtVirtualKeyboard__WordCandidateListSettings_t {
    QByteArrayData data[8];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__WordCandidateListSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__WordCandidateListSettings_t qt_meta_stringdata_QtVirtualKeyboard__WordCandidateListSettings = {
    {
QT_MOC_LITERAL(0, 0, 44), // "QtVirtualKeyboard::WordCandid..."
QT_MOC_LITERAL(1, 45, 20), // "autoHideDelayChanged"
QT_MOC_LITERAL(2, 66, 0), // ""
QT_MOC_LITERAL(3, 67, 20), // "alwaysVisibleChanged"
QT_MOC_LITERAL(4, 88, 21), // "autoCommitWordChanged"
QT_MOC_LITERAL(5, 110, 13), // "autoHideDelay"
QT_MOC_LITERAL(6, 124, 13), // "alwaysVisible"
QT_MOC_LITERAL(7, 138, 14) // "autoCommitWord"

    },
    "QtVirtualKeyboard::WordCandidateListSettings\0"
    "autoHideDelayChanged\0\0alwaysVisibleChanged\0"
    "autoCommitWordChanged\0autoHideDelay\0"
    "alwaysVisible\0autoCommitWord"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__WordCandidateListSettings[] = {

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
       6, QMetaType::Bool, 0x00495103,
       7, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void QtVirtualKeyboard::WordCandidateListSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WordCandidateListSettings *_t = static_cast<WordCandidateListSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->autoHideDelayChanged(); break;
        case 1: _t->alwaysVisibleChanged(); break;
        case 2: _t->autoCommitWordChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WordCandidateListSettings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WordCandidateListSettings::autoHideDelayChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WordCandidateListSettings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WordCandidateListSettings::alwaysVisibleChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WordCandidateListSettings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WordCandidateListSettings::autoCommitWordChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        WordCandidateListSettings *_t = static_cast<WordCandidateListSettings *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->autoHideDelay(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->alwaysVisible(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->autoCommitWord(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        WordCandidateListSettings *_t = static_cast<WordCandidateListSettings *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAutoHideDelay(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setAlwaysVisible(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setAutoCommitWord(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject QtVirtualKeyboard::WordCandidateListSettings::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__WordCandidateListSettings.data,
      qt_meta_data_QtVirtualKeyboard__WordCandidateListSettings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::WordCandidateListSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::WordCandidateListSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__WordCandidateListSettings.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtVirtualKeyboard::WordCandidateListSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QtVirtualKeyboard::WordCandidateListSettings::autoHideDelayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtVirtualKeyboard::WordCandidateListSettings::alwaysVisibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QtVirtualKeyboard::WordCandidateListSettings::autoCommitWordChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
