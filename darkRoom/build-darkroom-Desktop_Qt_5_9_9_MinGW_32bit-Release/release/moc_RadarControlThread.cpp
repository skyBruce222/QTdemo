/****************************************************************************
** Meta object code from reading C++ file 'RadarControlThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Darkroom_mz_ok_0628/RadarControlThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RadarControlThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RadarControlThread_t {
    QByteArrayData data[20];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RadarControlThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RadarControlThread_t qt_meta_stringdata_RadarControlThread = {
    {
QT_MOC_LITERAL(0, 0, 18), // "RadarControlThread"
QT_MOC_LITERAL(1, 19, 10), // "SendString"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "msg"
QT_MOC_LITERAL(4, 35, 15), // "SerialDataReach"
QT_MOC_LITERAL(5, 51, 1), // "x"
QT_MOC_LITERAL(6, 53, 1), // "y"
QT_MOC_LITERAL(7, 55, 1), // "z"
QT_MOC_LITERAL(8, 57, 11), // "adjust_fail"
QT_MOC_LITERAL(9, 69, 14), // "adjust_success"
QT_MOC_LITERAL(10, 84, 8), // "send_uid"
QT_MOC_LITERAL(11, 93, 3), // "uid"
QT_MOC_LITERAL(12, 97, 14), // "signalDataDeal"
QT_MOC_LITERAL(13, 112, 6), // "t_iAnt"
QT_MOC_LITERAL(14, 119, 7), // "t_iPeak"
QT_MOC_LITERAL(15, 127, 18), // "action_adjust_slot"
QT_MOC_LITERAL(16, 146, 19), // "action_restart_slot"
QT_MOC_LITERAL(17, 166, 18), // "action_output_slot"
QT_MOC_LITERAL(18, 185, 3), // "out"
QT_MOC_LITERAL(19, 189, 19) // "action_get_uid_slot"

    },
    "RadarControlThread\0SendString\0\0msg\0"
    "SerialDataReach\0x\0y\0z\0adjust_fail\0"
    "adjust_success\0send_uid\0uid\0signalDataDeal\0"
    "t_iAnt\0t_iPeak\0action_adjust_slot\0"
    "action_restart_slot\0action_output_slot\0"
    "out\0action_get_uid_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RadarControlThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    3,   67,    2, 0x06 /* Public */,
       8,    1,   74,    2, 0x06 /* Public */,
       9,    0,   77,    2, 0x06 /* Public */,
      10,    1,   78,    2, 0x06 /* Public */,
      12,    2,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,   86,    2, 0x0a /* Public */,
      16,    0,   87,    2, 0x0a /* Public */,
      17,    1,   88,    2, 0x0a /* Public */,
      19,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    5,    6,    7,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,

       0        // eod
};

void RadarControlThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RadarControlThread *_t = static_cast<RadarControlThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SerialDataReach((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->adjust_fail((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->adjust_success(); break;
        case 4: _t->send_uid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->signalDataDeal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->action_adjust_slot(); break;
        case 7: _t->action_restart_slot(); break;
        case 8: _t->action_output_slot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->action_get_uid_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RadarControlThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RadarControlThread::SendString)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RadarControlThread::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RadarControlThread::SerialDataReach)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RadarControlThread::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RadarControlThread::adjust_fail)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RadarControlThread::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RadarControlThread::adjust_success)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (RadarControlThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RadarControlThread::send_uid)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (RadarControlThread::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RadarControlThread::signalDataDeal)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject RadarControlThread::staticMetaObject = {
    { &BaseControlThread::staticMetaObject, qt_meta_stringdata_RadarControlThread.data,
      qt_meta_data_RadarControlThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RadarControlThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RadarControlThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RadarControlThread.stringdata0))
        return static_cast<void*>(this);
    return BaseControlThread::qt_metacast(_clname);
}

int RadarControlThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseControlThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void RadarControlThread::SendString(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RadarControlThread::SerialDataReach(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RadarControlThread::adjust_fail(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RadarControlThread::adjust_success()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void RadarControlThread::send_uid(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RadarControlThread::signalDataDeal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
