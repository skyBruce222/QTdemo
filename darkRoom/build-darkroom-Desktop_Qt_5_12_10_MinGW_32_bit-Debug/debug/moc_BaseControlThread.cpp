/****************************************************************************
** Meta object code from reading C++ file 'BaseControlThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Darkroom_mz_ok_0628/BaseControlThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BaseControlThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BaseControlThread_t {
    QByteArrayData data[17];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseControlThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseControlThread_t qt_meta_stringdata_BaseControlThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "BaseControlThread"
QT_MOC_LITERAL(1, 18, 9), // "checkopen"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "justic"
QT_MOC_LITERAL(4, 36, 4), // "port"
QT_MOC_LITERAL(5, 41, 14), // "wrongdetectone"
QT_MOC_LITERAL(6, 56, 14), // "wrongdetecttwo"
QT_MOC_LITERAL(7, 71, 18), // "availableportnames"
QT_MOC_LITERAL(8, 90, 14), // "QList<QString>"
QT_MOC_LITERAL(9, 105, 5), // "ports"
QT_MOC_LITERAL(10, 111, 17), // "serialChangedslot"
QT_MOC_LITERAL(11, 129, 8), // "portname"
QT_MOC_LITERAL(12, 138, 4), // "rate"
QT_MOC_LITERAL(13, 143, 8), // "databits"
QT_MOC_LITERAL(14, 152, 8), // "stopbits"
QT_MOC_LITERAL(15, 161, 6), // "parity"
QT_MOC_LITERAL(16, 168, 23) // "availableportdetectslot"

    },
    "BaseControlThread\0checkopen\0\0justic\0"
    "port\0wrongdetectone\0wrongdetecttwo\0"
    "availableportnames\0QList<QString>\0"
    "ports\0serialChangedslot\0portname\0rate\0"
    "databits\0stopbits\0parity\0"
    "availableportdetectslot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseControlThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    0,   49,    2, 0x06 /* Public */,
       6,    0,   50,    2, 0x06 /* Public */,
       7,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    5,   54,    2, 0x0a /* Public */,
      16,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   12,   13,   14,   15,
    QMetaType::Void,

       0        // eod
};

void BaseControlThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BaseControlThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkopen((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->wrongdetectone(); break;
        case 2: _t->wrongdetecttwo(); break;
        case 3: _t->availableportnames((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 4: _t->serialChangedslot((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 5: _t->availableportdetectslot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BaseControlThread::*)(bool , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseControlThread::checkopen)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BaseControlThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseControlThread::wrongdetectone)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BaseControlThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseControlThread::wrongdetecttwo)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BaseControlThread::*)(QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseControlThread::availableportnames)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BaseControlThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_BaseControlThread.data,
    qt_meta_data_BaseControlThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BaseControlThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseControlThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BaseControlThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int BaseControlThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void BaseControlThread::checkopen(bool _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BaseControlThread::wrongdetectone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BaseControlThread::wrongdetecttwo()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BaseControlThread::availableportnames(QList<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
