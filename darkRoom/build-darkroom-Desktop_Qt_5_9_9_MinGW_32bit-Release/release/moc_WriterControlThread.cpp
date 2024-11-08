/****************************************************************************
** Meta object code from reading C++ file 'WriterControlThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Darkroom_mz_ok_0628/WriterControlThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WriterControlThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WriterControlThread_t {
    QByteArrayData data[19];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WriterControlThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WriterControlThread_t qt_meta_stringdata_WriterControlThread = {
    {
QT_MOC_LITERAL(0, 0, 19), // "WriterControlThread"
QT_MOC_LITERAL(1, 20, 15), // "judge_qualified"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 3), // "val"
QT_MOC_LITERAL(4, 41, 22), // "judge_disqualification"
QT_MOC_LITERAL(5, 64, 15), // "data_reach_slot"
QT_MOC_LITERAL(6, 80, 1), // "x"
QT_MOC_LITERAL(7, 82, 1), // "y"
QT_MOC_LITERAL(8, 84, 1), // "z"
QT_MOC_LITERAL(9, 86, 17), // "set_measures_slot"
QT_MOC_LITERAL(10, 104, 13), // "QList<double>"
QT_MOC_LITERAL(11, 118, 11), // "measurelist"
QT_MOC_LITERAL(12, 130, 17), // "action_write_slot"
QT_MOC_LITERAL(13, 148, 5), // "write"
QT_MOC_LITERAL(14, 154, 22), // "precision_changed_slot"
QT_MOC_LITERAL(15, 177, 9), // "pricision"
QT_MOC_LITERAL(16, 187, 20), // "radarid_changed_slot"
QT_MOC_LITERAL(17, 208, 2), // "id"
QT_MOC_LITERAL(18, 211, 16) // "rename_file_slot"

    },
    "WriterControlThread\0judge_qualified\0"
    "\0val\0judge_disqualification\0data_reach_slot\0"
    "x\0y\0z\0set_measures_slot\0QList<double>\0"
    "measurelist\0action_write_slot\0write\0"
    "precision_changed_slot\0pricision\0"
    "radarid_changed_slot\0id\0rename_file_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WriterControlThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   65,    2, 0x0a /* Public */,
       5,    1,   72,    2, 0x0a /* Public */,
       9,    1,   75,    2, 0x0a /* Public */,
      12,    1,   78,    2, 0x0a /* Public */,
      14,    1,   81,    2, 0x0a /* Public */,
      16,    1,   84,    2, 0x0a /* Public */,
      18,    0,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    6,    7,    8,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,

       0        // eod
};

void WriterControlThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WriterControlThread *_t = static_cast<WriterControlThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->judge_qualified((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->judge_disqualification((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->data_reach_slot((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 3: _t->data_reach_slot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->set_measures_slot((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 5: _t->action_write_slot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->precision_changed_slot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->radarid_changed_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->rename_file_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WriterControlThread::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WriterControlThread::judge_qualified)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WriterControlThread::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WriterControlThread::judge_disqualification)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject WriterControlThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_WriterControlThread.data,
      qt_meta_data_WriterControlThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WriterControlThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WriterControlThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WriterControlThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int WriterControlThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void WriterControlThread::judge_qualified(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WriterControlThread::judge_disqualification(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
