/****************************************************************************
** Meta object code from reading C++ file 'plugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QVirtualKeyboardPlugin_t {
    QByteArrayData data[1];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QVirtualKeyboardPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QVirtualKeyboardPlugin_t qt_meta_stringdata_QVirtualKeyboardPlugin = {
    {
QT_MOC_LITERAL(0, 0, 22) // "QVirtualKeyboardPlugin"

    },
    "QVirtualKeyboardPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QVirtualKeyboardPlugin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void QVirtualKeyboardPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QVirtualKeyboardPlugin::staticMetaObject = {
    { &QPlatformInputContextPlugin::staticMetaObject, qt_meta_stringdata_QVirtualKeyboardPlugin.data,
      qt_meta_data_QVirtualKeyboardPlugin,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QVirtualKeyboardPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QVirtualKeyboardPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QVirtualKeyboardPlugin.stringdata0))
        return static_cast<void*>(this);
    return QPlatformInputContextPlugin::qt_metacast(_clname);
}

int QVirtualKeyboardPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlatformInputContextPlugin::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0xec, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    ';',  0x00, 'o',  'r',  'g',  '.',  'q',  't', 
    '-',  'p',  'r',  'o',  'j',  'e',  'c',  't', 
    '.',  'Q',  't',  '.',  'Q',  'P',  'l',  'a', 
    't',  'f',  'o',  'r',  'm',  'I',  'n',  'p', 
    'u',  't',  'C',  'o',  'n',  't',  'e',  'x', 
    't',  'F',  'a',  'c',  't',  'o',  'r',  'y', 
    'I',  'n',  't',  'e',  'r',  'f',  'a',  'c', 
    'e',  '.',  '5',  '.',  '1',  0x00, 0x00, 0x00,
    0x1b, 0x0d, 0x00, 0x00, 0x09, 0x00, 'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x00,
    0x16, 0x00, 'Q',  'V',  'i',  'r',  't',  'u', 
    'a',  'l',  'K',  'e',  'y',  'b',  'o',  'a', 
    'r',  'd',  'P',  'l',  'u',  'g',  'i',  'n', 
    0x1a, '@',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x11, 0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, 0x95, 0x15, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, '@',  0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00, '<',  0x00, 0x00, 0x00,
    0x14, 0x03, 0x00, 0x00, 0x04, 0x00, 'K',  'e', 
    'y',  's',  0x00, 0x00, '$',  0x00, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, ' ',  0x00, 0x00, 0x00,
    0x11, 0x00, 'q',  't',  'v',  'i',  'r',  't', 
    'u',  'a',  'l',  'k',  'e',  'y',  'b',  'o', 
    'a',  'r',  'd',  0x00, 0x8b, 0x01, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x9c, 0x00, 0x00, 0x00, 'X',  0x00, 0x00, 0x00,
    0x90, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0xec, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    ';',  0x00, 'o',  'r',  'g',  '.',  'q',  't', 
    '-',  'p',  'r',  'o',  'j',  'e',  'c',  't', 
    '.',  'Q',  't',  '.',  'Q',  'P',  'l',  'a', 
    't',  'f',  'o',  'r',  'm',  'I',  'n',  'p', 
    'u',  't',  'C',  'o',  'n',  't',  'e',  'x', 
    't',  'F',  'a',  'c',  't',  'o',  'r',  'y', 
    'I',  'n',  't',  'e',  'r',  'f',  'a',  'c', 
    'e',  '.',  '5',  '.',  '1',  0x00, 0x00, 0x00,
    0x15, 0x0d, 0x00, 0x00, 0x08, 0x00, 'M',  'e', 
    't',  'a',  'D',  'a',  't',  'a',  0x00, 0x00,
    '@',  0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    '<',  0x00, 0x00, 0x00, 0x14, 0x03, 0x00, 0x00,
    0x04, 0x00, 'K',  'e',  'y',  's',  0x00, 0x00,
    '$',  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    ' ',  0x00, 0x00, 0x00, 0x11, 0x00, 'q',  't', 
    'v',  'i',  'r',  't',  'u',  'a',  'l',  'k', 
    'e',  'y',  'b',  'o',  'a',  'r',  'd',  0x00,
    0x8b, 0x01, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x1b, 0x17, 0x00, 0x00, 0x09, 0x00, 'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x00,
    0x16, 0x00, 'Q',  'V',  'i',  'r',  't',  'u', 
    'a',  'l',  'K',  'e',  'y',  'b',  'o',  'a', 
    'r',  'd',  'P',  'l',  'u',  'g',  'i',  'n', 
    '1',  0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, 0x1a, '@',  0xa1, 0x00,
    0x07, 0x00, 'v',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    'X',  0x00, 0x00, 0x00, 0xa8, 0x00, 0x00, 0x00,
    0xd0, 0x00, 0x00, 0x00, 0xdc, 0x00, 0x00, 0x00
};
#endif // QT_NO_DEBUG

QT_MOC_EXPORT_PLUGIN(QVirtualKeyboardPlugin, QVirtualKeyboardPlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
