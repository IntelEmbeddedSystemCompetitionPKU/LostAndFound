/****************************************************************************
** Meta object code from reading C++ file 'inputengine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../qtvirtualkeyboard/src/virtualkeyboard/inputengine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inputengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__InputEngine_t {
    QByteArrayData data[80];
    char stringdata0[1249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__InputEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__InputEngine_t qt_meta_stringdata_QtVirtualKeyboard__InputEngine = {
    {
QT_MOC_LITERAL(0, 0, 30), // "QtVirtualKeyboard::InputEngine"
QT_MOC_LITERAL(1, 31, 17), // "virtualKeyClicked"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 7), // "Qt::Key"
QT_MOC_LITERAL(4, 58, 3), // "key"
QT_MOC_LITERAL(5, 62, 4), // "text"
QT_MOC_LITERAL(6, 67, 21), // "Qt::KeyboardModifiers"
QT_MOC_LITERAL(7, 89, 9), // "modifiers"
QT_MOC_LITERAL(8, 99, 12), // "isAutoRepeat"
QT_MOC_LITERAL(9, 112, 16), // "activeKeyChanged"
QT_MOC_LITERAL(10, 129, 18), // "previousKeyChanged"
QT_MOC_LITERAL(11, 148, 18), // "inputMethodChanged"
QT_MOC_LITERAL(12, 167, 16), // "inputMethodReset"
QT_MOC_LITERAL(13, 184, 17), // "inputMethodUpdate"
QT_MOC_LITERAL(14, 202, 17), // "inputModesChanged"
QT_MOC_LITERAL(15, 220, 16), // "inputModeChanged"
QT_MOC_LITERAL(16, 237, 30), // "patternRecognitionModesChanged"
QT_MOC_LITERAL(17, 268, 29), // "wordCandidateListModelChanged"
QT_MOC_LITERAL(18, 298, 35), // "wordCandidateListVisibleHintC..."
QT_MOC_LITERAL(19, 334, 5), // "reset"
QT_MOC_LITERAL(20, 340, 6), // "update"
QT_MOC_LITERAL(21, 347, 12), // "shiftChanged"
QT_MOC_LITERAL(22, 360, 25), // "updateSelectionListModels"
QT_MOC_LITERAL(23, 386, 16), // "updateInputModes"
QT_MOC_LITERAL(24, 403, 15), // "virtualKeyPress"
QT_MOC_LITERAL(25, 419, 6), // "repeat"
QT_MOC_LITERAL(26, 426, 16), // "virtualKeyCancel"
QT_MOC_LITERAL(27, 443, 17), // "virtualKeyRelease"
QT_MOC_LITERAL(28, 461, 15), // "virtualKeyClick"
QT_MOC_LITERAL(29, 477, 10), // "traceBegin"
QT_MOC_LITERAL(30, 488, 25), // "QtVirtualKeyboard::Trace*"
QT_MOC_LITERAL(31, 514, 7), // "traceId"
QT_MOC_LITERAL(32, 522, 54), // "QtVirtualKeyboard::InputEngin..."
QT_MOC_LITERAL(33, 577, 22), // "patternRecognitionMode"
QT_MOC_LITERAL(34, 600, 22), // "traceCaptureDeviceInfo"
QT_MOC_LITERAL(35, 623, 15), // "traceScreenInfo"
QT_MOC_LITERAL(36, 639, 8), // "traceEnd"
QT_MOC_LITERAL(37, 648, 5), // "trace"
QT_MOC_LITERAL(38, 654, 8), // "reselect"
QT_MOC_LITERAL(39, 663, 14), // "cursorPosition"
QT_MOC_LITERAL(40, 678, 13), // "ReselectFlags"
QT_MOC_LITERAL(41, 692, 13), // "reselectFlags"
QT_MOC_LITERAL(42, 706, 9), // "activeKey"
QT_MOC_LITERAL(43, 716, 11), // "previousKey"
QT_MOC_LITERAL(44, 728, 11), // "inputMethod"
QT_MOC_LITERAL(45, 740, 39), // "QtVirtualKeyboard::AbstractIn..."
QT_MOC_LITERAL(46, 780, 10), // "inputModes"
QT_MOC_LITERAL(47, 791, 10), // "QList<int>"
QT_MOC_LITERAL(48, 802, 9), // "inputMode"
QT_MOC_LITERAL(49, 812, 9), // "InputMode"
QT_MOC_LITERAL(50, 822, 23), // "patternRecognitionModes"
QT_MOC_LITERAL(51, 846, 22), // "wordCandidateListModel"
QT_MOC_LITERAL(52, 869, 38), // "QtVirtualKeyboard::SelectionL..."
QT_MOC_LITERAL(53, 908, 28), // "wordCandidateListVisibleHint"
QT_MOC_LITERAL(54, 937, 8), // "TextCase"
QT_MOC_LITERAL(55, 946, 5), // "Lower"
QT_MOC_LITERAL(56, 952, 5), // "Upper"
QT_MOC_LITERAL(57, 958, 5), // "Latin"
QT_MOC_LITERAL(58, 964, 7), // "Numeric"
QT_MOC_LITERAL(59, 972, 8), // "Dialable"
QT_MOC_LITERAL(60, 981, 6), // "Pinyin"
QT_MOC_LITERAL(61, 988, 7), // "Cangjie"
QT_MOC_LITERAL(62, 996, 6), // "Zhuyin"
QT_MOC_LITERAL(63, 1003, 6), // "Hangul"
QT_MOC_LITERAL(64, 1010, 8), // "Hiragana"
QT_MOC_LITERAL(65, 1019, 8), // "Katakana"
QT_MOC_LITERAL(66, 1028, 14), // "FullwidthLatin"
QT_MOC_LITERAL(67, 1043, 5), // "Greek"
QT_MOC_LITERAL(68, 1049, 8), // "Cyrillic"
QT_MOC_LITERAL(69, 1058, 6), // "Arabic"
QT_MOC_LITERAL(70, 1065, 6), // "Hebrew"
QT_MOC_LITERAL(71, 1072, 18), // "ChineseHandwriting"
QT_MOC_LITERAL(72, 1091, 19), // "JapaneseHandwriting"
QT_MOC_LITERAL(73, 1111, 17), // "KoreanHandwriting"
QT_MOC_LITERAL(74, 1129, 22), // "PatternRecognitionMode"
QT_MOC_LITERAL(75, 1152, 26), // "PatternRecognitionDisabled"
QT_MOC_LITERAL(76, 1179, 23), // "HandwritingRecoginition"
QT_MOC_LITERAL(77, 1203, 16), // "WordBeforeCursor"
QT_MOC_LITERAL(78, 1220, 15), // "WordAfterCursor"
QT_MOC_LITERAL(79, 1236, 12) // "WordAtCursor"

    },
    "QtVirtualKeyboard::InputEngine\0"
    "virtualKeyClicked\0\0Qt::Key\0key\0text\0"
    "Qt::KeyboardModifiers\0modifiers\0"
    "isAutoRepeat\0activeKeyChanged\0"
    "previousKeyChanged\0inputMethodChanged\0"
    "inputMethodReset\0inputMethodUpdate\0"
    "inputModesChanged\0inputModeChanged\0"
    "patternRecognitionModesChanged\0"
    "wordCandidateListModelChanged\0"
    "wordCandidateListVisibleHintChanged\0"
    "reset\0update\0shiftChanged\0"
    "updateSelectionListModels\0updateInputModes\0"
    "virtualKeyPress\0repeat\0virtualKeyCancel\0"
    "virtualKeyRelease\0virtualKeyClick\0"
    "traceBegin\0QtVirtualKeyboard::Trace*\0"
    "traceId\0QtVirtualKeyboard::InputEngine::PatternRecognitionMode\0"
    "patternRecognitionMode\0traceCaptureDeviceInfo\0"
    "traceScreenInfo\0traceEnd\0trace\0reselect\0"
    "cursorPosition\0ReselectFlags\0reselectFlags\0"
    "activeKey\0previousKey\0inputMethod\0"
    "QtVirtualKeyboard::AbstractInputMethod*\0"
    "inputModes\0QList<int>\0inputMode\0"
    "InputMode\0patternRecognitionModes\0"
    "wordCandidateListModel\0"
    "QtVirtualKeyboard::SelectionListModel*\0"
    "wordCandidateListVisibleHint\0TextCase\0"
    "Lower\0Upper\0Latin\0Numeric\0Dialable\0"
    "Pinyin\0Cangjie\0Zhuyin\0Hangul\0Hiragana\0"
    "Katakana\0FullwidthLatin\0Greek\0Cyrillic\0"
    "Arabic\0Hebrew\0ChineseHandwriting\0"
    "JapaneseHandwriting\0KoreanHandwriting\0"
    "PatternRecognitionMode\0"
    "PatternRecognitionDisabled\0"
    "HandwritingRecoginition\0WordBeforeCursor\0"
    "WordAfterCursor\0WordAtCursor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__InputEngine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       8,  198, // properties
       4,  230, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  129,    2, 0x06 /* Public */,
       9,    1,  138,    2, 0x06 /* Public */,
      10,    1,  141,    2, 0x06 /* Public */,
      11,    0,  144,    2, 0x06 /* Public */,
      12,    0,  145,    2, 0x06 /* Public */,
      13,    0,  146,    2, 0x06 /* Public */,
      14,    0,  147,    2, 0x06 /* Public */,
      15,    0,  148,    2, 0x06 /* Public */,
      16,    0,  149,    2, 0x06 /* Public */,
      17,    0,  150,    2, 0x06 /* Public */,
      18,    0,  151,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,  152,    2, 0x08 /* Private */,
      20,    0,  153,    2, 0x08 /* Private */,
      21,    0,  154,    2, 0x08 /* Private */,
      22,    0,  155,    2, 0x08 /* Private */,
      23,    0,  156,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      24,    4,  157,    2, 0x02 /* Public */,
      26,    0,  166,    2, 0x02 /* Public */,
      27,    3,  167,    2, 0x02 /* Public */,
      28,    3,  174,    2, 0x02 /* Public */,
      29,    4,  181,    2, 0x02 /* Public */,
      36,    1,  190,    2, 0x02 /* Public */,
      38,    2,  193,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 6, QMetaType::Bool,    4,    5,    7,    8,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Bool, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 6, QMetaType::Bool,    4,    5,    7,   25,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Bool, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 6,    4,    5,    7,
    0x80000000 | 30, QMetaType::Int, 0x80000000 | 32, QMetaType::QVariantMap, QMetaType::QVariantMap,   31,   33,   34,   35,
    QMetaType::Bool, 0x80000000 | 30,   37,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 40,   39,   41,

 // properties: name, type, flags
      42, 0x80000000 | 3, 0x00495009,
      43, 0x80000000 | 3, 0x00495009,
      44, 0x80000000 | 45, 0x0049510b,
      46, 0x80000000 | 47, 0x00495009,
      48, 0x80000000 | 49, 0x0049510b,
      50, 0x80000000 | 47, 0x00495009,
      51, 0x80000000 | 52, 0x00495009,
      53, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       1,
       2,
       3,
       6,
       7,
       8,
       9,
      10,

 // enums: name, flags, count, data
      54, 0x0,    2,  246,
      49, 0x0,   17,  250,
      74, 0x0,    2,  284,
      40, 0x1,    3,  288,

 // enum data: key, value
      55, uint(QtVirtualKeyboard::InputEngine::Lower),
      56, uint(QtVirtualKeyboard::InputEngine::Upper),
      57, uint(QtVirtualKeyboard::InputEngine::Latin),
      58, uint(QtVirtualKeyboard::InputEngine::Numeric),
      59, uint(QtVirtualKeyboard::InputEngine::Dialable),
      60, uint(QtVirtualKeyboard::InputEngine::Pinyin),
      61, uint(QtVirtualKeyboard::InputEngine::Cangjie),
      62, uint(QtVirtualKeyboard::InputEngine::Zhuyin),
      63, uint(QtVirtualKeyboard::InputEngine::Hangul),
      64, uint(QtVirtualKeyboard::InputEngine::Hiragana),
      65, uint(QtVirtualKeyboard::InputEngine::Katakana),
      66, uint(QtVirtualKeyboard::InputEngine::FullwidthLatin),
      67, uint(QtVirtualKeyboard::InputEngine::Greek),
      68, uint(QtVirtualKeyboard::InputEngine::Cyrillic),
      69, uint(QtVirtualKeyboard::InputEngine::Arabic),
      70, uint(QtVirtualKeyboard::InputEngine::Hebrew),
      71, uint(QtVirtualKeyboard::InputEngine::ChineseHandwriting),
      72, uint(QtVirtualKeyboard::InputEngine::JapaneseHandwriting),
      73, uint(QtVirtualKeyboard::InputEngine::KoreanHandwriting),
      75, uint(QtVirtualKeyboard::InputEngine::PatternRecognitionDisabled),
      76, uint(QtVirtualKeyboard::InputEngine::HandwritingRecoginition),
      77, uint(QtVirtualKeyboard::InputEngine::WordBeforeCursor),
      78, uint(QtVirtualKeyboard::InputEngine::WordAfterCursor),
      79, uint(QtVirtualKeyboard::InputEngine::WordAtCursor),

       0        // eod
};

void QtVirtualKeyboard::InputEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InputEngine *_t = static_cast<InputEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->virtualKeyClicked((*reinterpret_cast< Qt::Key(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 1: _t->activeKeyChanged((*reinterpret_cast< Qt::Key(*)>(_a[1]))); break;
        case 2: _t->previousKeyChanged((*reinterpret_cast< Qt::Key(*)>(_a[1]))); break;
        case 3: _t->inputMethodChanged(); break;
        case 4: _t->inputMethodReset(); break;
        case 5: _t->inputMethodUpdate(); break;
        case 6: _t->inputModesChanged(); break;
        case 7: _t->inputModeChanged(); break;
        case 8: _t->patternRecognitionModesChanged(); break;
        case 9: _t->wordCandidateListModelChanged(); break;
        case 10: _t->wordCandidateListVisibleHintChanged(); break;
        case 11: _t->reset(); break;
        case 12: _t->update(); break;
        case 13: _t->shiftChanged(); break;
        case 14: _t->updateSelectionListModels(); break;
        case 15: _t->updateInputModes(); break;
        case 16: { bool _r = _t->virtualKeyPress((*reinterpret_cast< Qt::Key(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->virtualKeyCancel(); break;
        case 18: { bool _r = _t->virtualKeyRelease((*reinterpret_cast< Qt::Key(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { bool _r = _t->virtualKeyClick((*reinterpret_cast< Qt::Key(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: { QtVirtualKeyboard::Trace* _r = _t->traceBegin((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QtVirtualKeyboard::InputEngine::PatternRecognitionMode(*)>(_a[2])),(*reinterpret_cast< const QVariantMap(*)>(_a[3])),(*reinterpret_cast< const QVariantMap(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QtVirtualKeyboard::Trace**>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->traceEnd((*reinterpret_cast< QtVirtualKeyboard::Trace*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { bool _r = _t->reselect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const ReselectFlags(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (InputEngine::*_t)(Qt::Key , const QString & , Qt::KeyboardModifiers , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputEngine::virtualKeyClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (InputEngine::*_t)(Qt::Key );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputEngine::activeKeyChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (InputEngine::*_t)(Qt::Key );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputEngine::previousKeyChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (InputEngine::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputEngine::inputMethodChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (InputEngine::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputEngine::inputMethodReset)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (InputEngine::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputEngine::inputMethodUpdate)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (InputEngine::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputEngine::inputModesChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (InputEngine::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputEngine::inputModeChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (InputEngine::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputEngine::patternRecognitionModesChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (InputEngine::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputEngine::wordCandidateListModelChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (InputEngine::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputEngine::wordCandidateListVisibleHintChanged)) {
                *result = 10;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        InputEngine *_t = static_cast<InputEngine *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Qt::Key*>(_v) = _t->activeKey(); break;
        case 1: *reinterpret_cast< Qt::Key*>(_v) = _t->previousKey(); break;
        case 2: *reinterpret_cast< QtVirtualKeyboard::AbstractInputMethod**>(_v) = _t->inputMethod(); break;
        case 3: *reinterpret_cast< QList<int>*>(_v) = _t->inputModes(); break;
        case 4: *reinterpret_cast< InputMode*>(_v) = _t->inputMode(); break;
        case 5: *reinterpret_cast< QList<int>*>(_v) = _t->patternRecognitionModes(); break;
        case 6: *reinterpret_cast< QtVirtualKeyboard::SelectionListModel**>(_v) = _t->wordCandidateListModel(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->wordCandidateListVisibleHint(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        InputEngine *_t = static_cast<InputEngine *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setInputMethod(*reinterpret_cast< QtVirtualKeyboard::AbstractInputMethod**>(_v)); break;
        case 4: _t->setInputMode(*reinterpret_cast< InputMode*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QtVirtualKeyboard::InputEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtVirtualKeyboard__InputEngine.data,
      qt_meta_data_QtVirtualKeyboard__InputEngine,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtVirtualKeyboard::InputEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::InputEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__InputEngine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtVirtualKeyboard::InputEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
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
void QtVirtualKeyboard::InputEngine::virtualKeyClicked(Qt::Key _t1, const QString & _t2, Qt::KeyboardModifiers _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtVirtualKeyboard::InputEngine::activeKeyChanged(Qt::Key _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtVirtualKeyboard::InputEngine::previousKeyChanged(Qt::Key _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QtVirtualKeyboard::InputEngine::inputMethodChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QtVirtualKeyboard::InputEngine::inputMethodReset()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QtVirtualKeyboard::InputEngine::inputMethodUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QtVirtualKeyboard::InputEngine::inputModesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QtVirtualKeyboard::InputEngine::inputModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QtVirtualKeyboard::InputEngine::patternRecognitionModesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void QtVirtualKeyboard::InputEngine::wordCandidateListModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void QtVirtualKeyboard::InputEngine::wordCandidateListVisibleHintChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
