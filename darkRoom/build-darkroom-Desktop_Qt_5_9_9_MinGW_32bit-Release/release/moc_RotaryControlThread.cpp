/****************************************************************************
** Meta object code from reading C++ file 'RotaryControlThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Darkroom_mz_ok_0628/RotaryControlThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RotaryControlThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RotaryControlThread_t {
    QByteArrayData data[25];
    char stringdata0[293];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RotaryControlThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RotaryControlThread_t qt_meta_stringdata_RotaryControlThread = {
    {
QT_MOC_LITERAL(0, 0, 19), // "RotaryControlThread"
QT_MOC_LITERAL(1, 20, 9), // "SendBytes"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "data"
QT_MOC_LITERAL(4, 36, 10), // "SendString"
QT_MOC_LITERAL(5, 47, 17), // "PortMessageString"
QT_MOC_LITERAL(6, 65, 7), // "SendInt"
QT_MOC_LITERAL(7, 73, 14), // "PortMessageInt"
QT_MOC_LITERAL(8, 88, 10), // "SendDouble"
QT_MOC_LITERAL(9, 99, 15), // "SerialDataReach"
QT_MOC_LITERAL(10, 115, 4), // "val1"
QT_MOC_LITERAL(11, 120, 4), // "val2"
QT_MOC_LITERAL(12, 125, 4), // "val3"
QT_MOC_LITERAL(13, 130, 14), // "action_cw_slot"
QT_MOC_LITERAL(14, 145, 3), // "spd"
QT_MOC_LITERAL(15, 149, 6), // "target"
QT_MOC_LITERAL(16, 156, 15), // "action_ccw_slot"
QT_MOC_LITERAL(17, 172, 16), // "action_stop_slot"
QT_MOC_LITERAL(18, 189, 17), // "action_reset_slot"
QT_MOC_LITERAL(19, 207, 16), // "action_lead_slot"
QT_MOC_LITERAL(20, 224, 18), // "action_calibration"
QT_MOC_LITERAL(21, 243, 15), // "typechangedslot"
QT_MOC_LITERAL(22, 259, 4), // "type"
QT_MOC_LITERAL(23, 264, 17), // "getRotaryTypeslot"
QT_MOC_LITERAL(24, 282, 10) // "AngleType&"

    },
    "RotaryControlThread\0SendBytes\0\0data\0"
    "SendString\0PortMessageString\0SendInt\0"
    "PortMessageInt\0SendDouble\0SerialDataReach\0"
    "val1\0val2\0val3\0action_cw_slot\0spd\0"
    "target\0action_ccw_slot\0action_stop_slot\0"
    "action_reset_slot\0action_lead_slot\0"
    "action_calibration\0typechangedslot\0"
    "type\0getRotaryTypeslot\0AngleType&"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RotaryControlThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       6,    1,   90,    2, 0x06 /* Public */,
       8,    1,   93,    2, 0x06 /* Public */,
       9,    3,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    2,  103,    2, 0x0a /* Public */,
      16,    2,  108,    2, 0x0a /* Public */,
      17,    0,  113,    2, 0x0a /* Public */,
      18,    0,  114,    2, 0x0a /* Public */,
      19,    2,  115,    2, 0x0a /* Public */,
      20,    1,  120,    2, 0x0a /* Public */,
      21,    1,  123,    2, 0x0a /* Public */,
      21,    1,  126,    2, 0x0a /* Public */,
      23,    1,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   10,   11,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   14,   15,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   14,   15,
    QMetaType::Void, QMetaType::Float,   15,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, 0x80000000 | 24,   22,

       0        // eod
};

void RotaryControlThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RotaryControlThread *_t = static_cast<RotaryControlThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendBytes((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->SendString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->SendInt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SendDouble((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->SerialDataReach((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 5: _t->action_cw_slot((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 6: _t->action_ccw_slot((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 7: _t->action_stop_slot(); break;
        case 8: _t->action_reset_slot(); break;
        case 9: _t->action_lead_slot((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 10: _t->action_calibration((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->typechangedslot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->typechangedslot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->getRotaryTypeslot((*reinterpret_cast< AngleType(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RotaryControlThread::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RotaryControlThread::SendBytes)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RotaryControlThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RotaryControlThread::SendString)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RotaryControlThread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RotaryControlThread::SendInt)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RotaryControlThread::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RotaryControlThread::SendDouble)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (RotaryControlThread::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RotaryControlThread::SerialDataReach)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject RotaryControlThread::staticMetaObject = {
    { &BaseControlThread::staticMetaObject, qt_meta_stringdata_RotaryControlThread.data,
      qt_meta_data_RotaryControlThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RotaryControlThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RotaryControlThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RotaryControlThread.stringdata0))
        return static_cast<void*>(this);
    return BaseControlThread::qt_metacast(_clname);
}

int RotaryControlThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseControlThread::qt_metacall(_c, _id, _a);
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
void RotaryControlThread::SendBytes(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RotaryControlThread::SendString(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RotaryControlThread::SendInt(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RotaryControlThread::SendDouble(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RotaryControlThread::SerialDataReach(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
