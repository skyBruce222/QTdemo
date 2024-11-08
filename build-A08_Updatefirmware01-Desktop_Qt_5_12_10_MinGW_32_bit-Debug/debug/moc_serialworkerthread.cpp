/****************************************************************************
** Meta object code from reading C++ file 'serialworkerthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../A08_Updatefirmware_0928_1.0.4/serialworkerthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialworkerthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Serialworkerthread_t {
    QByteArrayData data[22];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Serialworkerthread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Serialworkerthread_t qt_meta_stringdata_Serialworkerthread = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Serialworkerthread"
QT_MOC_LITERAL(1, 19, 8), // "senddata"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "data"
QT_MOC_LITERAL(4, 34, 7), // "sendvar"
QT_MOC_LITERAL(5, 42, 28), // "sendprogressdlgupdatesignals"
QT_MOC_LITERAL(6, 71, 16), // "sendStatusSignal"
QT_MOC_LITERAL(7, 88, 6), // "status"
QT_MOC_LITERAL(8, 95, 11), // "senddatabin"
QT_MOC_LITERAL(9, 107, 1), // "x"
QT_MOC_LITERAL(10, 109, 7), // "sendcli"
QT_MOC_LITERAL(11, 117, 11), // "Serial_Read"
QT_MOC_LITERAL(12, 129, 17), // "write_serial_data"
QT_MOC_LITERAL(13, 147, 3), // "str"
QT_MOC_LITERAL(14, 151, 12), // "close_serial"
QT_MOC_LITERAL(15, 164, 11), // "open_serial"
QT_MOC_LITERAL(16, 176, 7), // "display"
QT_MOC_LITERAL(17, 184, 17), // "firmbinupdateslot"
QT_MOC_LITERAL(18, 202, 11), // "firmbindata"
QT_MOC_LITERAL(19, 214, 8), // "baudrate"
QT_MOC_LITERAL(20, 223, 15), // "senddatabinSlot"
QT_MOC_LITERAL(21, 239, 11) // "readclislot"

    },
    "Serialworkerthread\0senddata\0\0data\0"
    "sendvar\0sendprogressdlgupdatesignals\0"
    "sendStatusSignal\0status\0senddatabin\0"
    "x\0sendcli\0Serial_Read\0write_serial_data\0"
    "str\0close_serial\0open_serial\0display\0"
    "firmbinupdateslot\0firmbindata\0baudrate\0"
    "senddatabinSlot\0readclislot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Serialworkerthread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       5,    1,   90,    2, 0x06 /* Public */,
       6,    1,   93,    2, 0x06 /* Public */,
       8,    1,   96,    2, 0x06 /* Public */,
      10,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  102,    2, 0x0a /* Public */,
      12,    1,  103,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    1,  107,    2, 0x0a /* Public */,
      16,    0,  110,    2, 0x0a /* Public */,
      17,    2,  111,    2, 0x0a /* Public */,
      20,    1,  116,    2, 0x0a /* Public */,
      21,    0,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,   18,   19,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

void Serialworkerthread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Serialworkerthread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->senddata((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->sendvar((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendprogressdlgupdatesignals((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sendStatusSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->senddatabin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->sendcli((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->Serial_Read(); break;
        case 7: _t->write_serial_data((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->close_serial(); break;
        case 9: _t->open_serial((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->display(); break;
        case 11: _t->firmbinupdateslot((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->senddatabinSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->readclislot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Serialworkerthread::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serialworkerthread::senddata)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Serialworkerthread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serialworkerthread::sendvar)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Serialworkerthread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serialworkerthread::sendprogressdlgupdatesignals)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Serialworkerthread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serialworkerthread::sendStatusSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Serialworkerthread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serialworkerthread::senddatabin)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Serialworkerthread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Serialworkerthread::sendcli)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Serialworkerthread::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Serialworkerthread.data,
    qt_meta_data_Serialworkerthread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Serialworkerthread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Serialworkerthread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Serialworkerthread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Serialworkerthread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Serialworkerthread::senddata(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Serialworkerthread::sendvar(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Serialworkerthread::sendprogressdlgupdatesignals(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Serialworkerthread::sendStatusSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Serialworkerthread::senddatabin(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Serialworkerthread::sendcli(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
