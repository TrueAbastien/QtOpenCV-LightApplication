/****************************************************************************
** Meta object code from reading C++ file 'ImageModifierApp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ImageModifierApp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageModifierApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageModifierApp_t {
    QByteArrayData data[6];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageModifierApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageModifierApp_t qt_meta_stringdata_ImageModifierApp = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ImageModifierApp"
QT_MOC_LITERAL(1, 17, 10), // "ResetImage"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "force"
QT_MOC_LITERAL(4, 35, 9), // "LoadImage"
QT_MOC_LITERAL(5, 45, 9) // "SaveImage"

    },
    "ImageModifierApp\0ResetImage\0\0force\0"
    "LoadImage\0SaveImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageModifierApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       1,    0,   37,    2, 0x2a /* Public | MethodCloned */,
       4,    0,   38,    2, 0x0a /* Public */,
       5,    0,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImageModifierApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageModifierApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ResetImage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ResetImage(); break;
        case 2: _t->LoadImage(); break;
        case 3: _t->SaveImage(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ImageModifierApp::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_ImageModifierApp.data,
    qt_meta_data_ImageModifierApp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImageModifierApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageModifierApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageModifierApp.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ImageModifierApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
