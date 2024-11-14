/****************************************************************************
** Meta object code from reading C++ file 'radarparasmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../radarparasmainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'radarparasmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_radarParasMainWindow_t {
    QByteArrayData data[16];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_radarParasMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_radarParasMainWindow_t qt_meta_stringdata_radarParasMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 20), // "radarParasMainWindow"
QT_MOC_LITERAL(1, 21, 11), // "setParasSig"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "unsigned char*"
QT_MOC_LITERAL(4, 49, 4), // "data"
QT_MOC_LITERAL(5, 54, 7), // "uint8_t"
QT_MOC_LITERAL(6, 62, 3), // "len"
QT_MOC_LITERAL(7, 66, 12), // "readParasSig"
QT_MOC_LITERAL(8, 79, 18), // "connectSucceedSlot"
QT_MOC_LITERAL(9, 98, 16), // "radarDataRespond"
QT_MOC_LITERAL(10, 115, 2), // "id"
QT_MOC_LITERAL(11, 118, 4), // "mode"
QT_MOC_LITERAL(12, 123, 4), // "baud"
QT_MOC_LITERAL(13, 128, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(14, 150, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(15, 174, 23) // "on_pushButton_2_clicked"

    },
    "radarParasMainWindow\0setParasSig\0\0"
    "unsigned char*\0data\0uint8_t\0len\0"
    "readParasSig\0connectSucceedSlot\0"
    "radarDataRespond\0id\0mode\0baud\0"
    "on_pushButton_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_radarParasMainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       7,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   55,    2, 0x0a /* Public */,
       9,    3,   58,    2, 0x0a /* Public */,
      13,    0,   65,    2, 0x08 /* Private */,
      14,    0,   66,    2, 0x08 /* Private */,
      15,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   10,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void radarParasMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<radarParasMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setParasSig((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2]))); break;
        case 1: _t->readParasSig(); break;
        case 2: _t->connectSucceedSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->radarDataRespond((*reinterpret_cast< unsigned char(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2])),(*reinterpret_cast< unsigned char(*)>(_a[3]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_3_clicked(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (radarParasMainWindow::*)(unsigned char * , uint8_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&radarParasMainWindow::setParasSig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (radarParasMainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&radarParasMainWindow::readParasSig)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject radarParasMainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_radarParasMainWindow.data,
    qt_meta_data_radarParasMainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *radarParasMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *radarParasMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_radarParasMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int radarParasMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void radarParasMainWindow::setParasSig(unsigned char * _t1, uint8_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void radarParasMainWindow::readParasSig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
