/****************************************************************************
** Meta object code from reading C++ file 'radarareamainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../radarareamainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'radarareamainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_radarAreaMainWindow_t {
    QByteArrayData data[11];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_radarAreaMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_radarAreaMainWindow_t qt_meta_stringdata_radarAreaMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 19), // "radarAreaMainWindow"
QT_MOC_LITERAL(1, 20, 10), // "setAreaSig"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "unsigned char*"
QT_MOC_LITERAL(4, 47, 7), // "uint8_t"
QT_MOC_LITERAL(5, 55, 11), // "readAreaSig"
QT_MOC_LITERAL(6, 67, 18), // "connectSucceedSlot"
QT_MOC_LITERAL(7, 86, 16), // "radarDataRespond"
QT_MOC_LITERAL(8, 103, 9), // "short int"
QT_MOC_LITERAL(9, 113, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(10, 135, 23) // "on_pushButton_2_clicked"

    },
    "radarAreaMainWindow\0setAreaSig\0\0"
    "unsigned char*\0uint8_t\0readAreaSig\0"
    "connectSucceedSlot\0radarDataRespond\0"
    "short int\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_radarAreaMainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   50,    2, 0x0a /* Public */,
       7,    6,   53,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8, 0x80000000 | 8, 0x80000000 | 8, 0x80000000 | 8, 0x80000000 | 8,    2,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void radarAreaMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<radarAreaMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setAreaSig((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2]))); break;
        case 1: _t->readAreaSig(); break;
        case 2: _t->connectSucceedSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->radarDataRespond((*reinterpret_cast< short int(*)>(_a[1])),(*reinterpret_cast< short int(*)>(_a[2])),(*reinterpret_cast< short int(*)>(_a[3])),(*reinterpret_cast< short int(*)>(_a[4])),(*reinterpret_cast< short int(*)>(_a[5])),(*reinterpret_cast< short int(*)>(_a[6]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (radarAreaMainWindow::*)(unsigned char * , uint8_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&radarAreaMainWindow::setAreaSig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (radarAreaMainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&radarAreaMainWindow::readAreaSig)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject radarAreaMainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_radarAreaMainWindow.data,
    qt_meta_data_radarAreaMainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *radarAreaMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *radarAreaMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_radarAreaMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int radarAreaMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void radarAreaMainWindow::setAreaSig(unsigned char * _t1, uint8_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void radarAreaMainWindow::readAreaSig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
