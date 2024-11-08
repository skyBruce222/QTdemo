/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Darkroom_mz_ok_0628/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[74];
    char stringdata0[1140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "RadarSerialChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "portname"
QT_MOC_LITERAL(4, 40, 8), // "baudrate"
QT_MOC_LITERAL(5, 49, 8), // "databits"
QT_MOC_LITERAL(6, 58, 8), // "stopbits"
QT_MOC_LITERAL(7, 67, 6), // "parity"
QT_MOC_LITERAL(8, 74, 19), // "RotarySerialChanged"
QT_MOC_LITERAL(9, 94, 11), // "typechanged"
QT_MOC_LITERAL(10, 106, 4), // "type"
QT_MOC_LITERAL(11, 111, 13), // "getRotaryType"
QT_MOC_LITERAL(12, 125, 10), // "AngleType&"
QT_MOC_LITERAL(13, 136, 13), // "action_adjust"
QT_MOC_LITERAL(14, 150, 13), // "action_output"
QT_MOC_LITERAL(15, 164, 6), // "output"
QT_MOC_LITERAL(16, 171, 12), // "set_measures"
QT_MOC_LITERAL(17, 184, 13), // "QList<double>"
QT_MOC_LITERAL(18, 198, 8), // "measures"
QT_MOC_LITERAL(19, 207, 11), // "action_lead"
QT_MOC_LITERAL(20, 219, 3), // "spd"
QT_MOC_LITERAL(21, 223, 6), // "target"
QT_MOC_LITERAL(22, 230, 12), // "action_write"
QT_MOC_LITERAL(23, 243, 5), // "write"
QT_MOC_LITERAL(24, 249, 11), // "rename_file"
QT_MOC_LITERAL(25, 261, 21), // "on_action_O_triggered"
QT_MOC_LITERAL(26, 283, 27), // "on_pushButtonDetect_clicked"
QT_MOC_LITERAL(27, 311, 8), // "waitUtil"
QT_MOC_LITERAL(28, 320, 15), // "maxMilliSeconds"
QT_MOC_LITERAL(29, 336, 13), // "detectProcess"
QT_MOC_LITERAL(30, 350, 5), // "angle"
QT_MOC_LITERAL(31, 356, 26), // "on_actionAbout_A_triggered"
QT_MOC_LITERAL(32, 383, 13), // "checkopenslot"
QT_MOC_LITERAL(33, 397, 6), // "justic"
QT_MOC_LITERAL(34, 404, 4), // "port"
QT_MOC_LITERAL(35, 409, 24), // "RotarySerialDataRechSlot"
QT_MOC_LITERAL(36, 434, 4), // "val1"
QT_MOC_LITERAL(37, 439, 4), // "val2"
QT_MOC_LITERAL(38, 444, 4), // "val3"
QT_MOC_LITERAL(39, 449, 18), // "wrongdetectoneslot"
QT_MOC_LITERAL(40, 468, 18), // "wrongdetecttwoslot"
QT_MOC_LITERAL(41, 487, 24), // "RadarSerialDataRechSlot2"
QT_MOC_LITERAL(42, 512, 6), // "t_iAnt"
QT_MOC_LITERAL(43, 519, 11), // "t_iRangeIdx"
QT_MOC_LITERAL(44, 531, 7), // "t_iPeak"
QT_MOC_LITERAL(45, 539, 19), // "radar_reselect_slot"
QT_MOC_LITERAL(46, 559, 20), // "rotary_reselect_slot"
QT_MOC_LITERAL(47, 580, 22), // "radar_adjust_fail_slot"
QT_MOC_LITERAL(48, 603, 3), // "msg"
QT_MOC_LITERAL(49, 607, 25), // "radar_adjust_success_slot"
QT_MOC_LITERAL(50, 633, 22), // "save_sate_changed_slot"
QT_MOC_LITERAL(51, 656, 4), // "save"
QT_MOC_LITERAL(52, 661, 16), // "adjust_fail_slot"
QT_MOC_LITERAL(53, 678, 19), // "adjust_success_slot"
QT_MOC_LITERAL(54, 698, 20), // "judge_qualified_slot"
QT_MOC_LITERAL(55, 719, 3), // "val"
QT_MOC_LITERAL(56, 723, 22), // "judge_disqualification"
QT_MOC_LITERAL(57, 746, 25), // "standard_distance_changed"
QT_MOC_LITERAL(58, 772, 18), // "speed_changed_slot"
QT_MOC_LITERAL(59, 791, 17), // "slotRotaryAddPort"
QT_MOC_LITERAL(60, 809, 10), // "t_qstrPort"
QT_MOC_LITERAL(61, 820, 17), // "slotRadarsAddPort"
QT_MOC_LITERAL(62, 838, 18), // "onButtonMinClicked"
QT_MOC_LITERAL(63, 857, 22), // "onButtonRestoreClicked"
QT_MOC_LITERAL(64, 880, 18), // "onButtonMaxClicked"
QT_MOC_LITERAL(65, 899, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(66, 920, 29), // "on_pushButton_refresh_clicked"
QT_MOC_LITERAL(67, 950, 37), // "on_comboBoxRotary_currentInde..."
QT_MOC_LITERAL(68, 988, 4), // "arg1"
QT_MOC_LITERAL(69, 993, 32), // "on_comboType_currentIndexChanged"
QT_MOC_LITERAL(70, 1026, 29), // "on_lineedit_Speed_textChanged"
QT_MOC_LITERAL(71, 1056, 37), // "on_comboBoxRadars_currentInde..."
QT_MOC_LITERAL(72, 1094, 16), // "ReceiveRadarInfo"
QT_MOC_LITERAL(73, 1111, 28) // "on_BtnGenerateReport_clicked"

    },
    "MainWindow\0RadarSerialChanged\0\0portname\0"
    "baudrate\0databits\0stopbits\0parity\0"
    "RotarySerialChanged\0typechanged\0type\0"
    "getRotaryType\0AngleType&\0action_adjust\0"
    "action_output\0output\0set_measures\0"
    "QList<double>\0measures\0action_lead\0"
    "spd\0target\0action_write\0write\0rename_file\0"
    "on_action_O_triggered\0on_pushButtonDetect_clicked\0"
    "waitUtil\0maxMilliSeconds\0detectProcess\0"
    "angle\0on_actionAbout_A_triggered\0"
    "checkopenslot\0justic\0port\0"
    "RotarySerialDataRechSlot\0val1\0val2\0"
    "val3\0wrongdetectoneslot\0wrongdetecttwoslot\0"
    "RadarSerialDataRechSlot2\0t_iAnt\0"
    "t_iRangeIdx\0t_iPeak\0radar_reselect_slot\0"
    "rotary_reselect_slot\0radar_adjust_fail_slot\0"
    "msg\0radar_adjust_success_slot\0"
    "save_sate_changed_slot\0save\0"
    "adjust_fail_slot\0adjust_success_slot\0"
    "judge_qualified_slot\0val\0"
    "judge_disqualification\0standard_distance_changed\0"
    "speed_changed_slot\0slotRotaryAddPort\0"
    "t_qstrPort\0slotRadarsAddPort\0"
    "onButtonMinClicked\0onButtonRestoreClicked\0"
    "onButtonMaxClicked\0onButtonCloseClicked\0"
    "on_pushButton_refresh_clicked\0"
    "on_comboBoxRotary_currentIndexChanged\0"
    "arg1\0on_comboType_currentIndexChanged\0"
    "on_lineedit_Speed_textChanged\0"
    "on_comboBoxRadars_currentIndexChanged\0"
    "ReceiveRadarInfo\0on_BtnGenerateReport_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      47,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,  249,    2, 0x06 /* Public */,
       8,    5,  260,    2, 0x06 /* Public */,
       9,    1,  271,    2, 0x06 /* Public */,
      11,    1,  274,    2, 0x06 /* Public */,
      13,    0,  277,    2, 0x06 /* Public */,
      14,    1,  278,    2, 0x06 /* Public */,
      16,    1,  281,    2, 0x06 /* Public */,
      19,    2,  284,    2, 0x06 /* Public */,
      22,    1,  289,    2, 0x06 /* Public */,
      24,    0,  292,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      25,    0,  293,    2, 0x08 /* Private */,
      26,    0,  294,    2, 0x08 /* Private */,
      27,    2,  295,    2, 0x08 /* Private */,
      27,    1,  300,    2, 0x28 /* Private | MethodCloned */,
      27,    1,  303,    2, 0x08 /* Private */,
      27,    0,  306,    2, 0x28 /* Private | MethodCloned */,
      29,    1,  307,    2, 0x08 /* Private */,
      31,    0,  310,    2, 0x08 /* Private */,
      32,    2,  311,    2, 0x0a /* Public */,
      35,    3,  316,    2, 0x0a /* Public */,
      39,    0,  323,    2, 0x0a /* Public */,
      40,    0,  324,    2, 0x0a /* Public */,
      41,    3,  325,    2, 0x0a /* Public */,
      45,    0,  332,    2, 0x0a /* Public */,
      46,    0,  333,    2, 0x0a /* Public */,
      47,    1,  334,    2, 0x0a /* Public */,
      49,    0,  337,    2, 0x0a /* Public */,
      50,    1,  338,    2, 0x0a /* Public */,
      52,    1,  341,    2, 0x0a /* Public */,
      53,    0,  344,    2, 0x0a /* Public */,
      54,    1,  345,    2, 0x0a /* Public */,
      56,    1,  348,    2, 0x0a /* Public */,
      57,    1,  351,    2, 0x0a /* Public */,
      58,    1,  354,    2, 0x0a /* Public */,
      59,    1,  357,    2, 0x0a /* Public */,
      61,    1,  360,    2, 0x0a /* Public */,
      62,    0,  363,    2, 0x08 /* Private */,
      63,    0,  364,    2, 0x08 /* Private */,
      64,    0,  365,    2, 0x08 /* Private */,
      65,    0,  366,    2, 0x08 /* Private */,
      66,    0,  367,    2, 0x08 /* Private */,
      67,    1,  368,    2, 0x08 /* Private */,
      69,    1,  371,    2, 0x08 /* Private */,
      70,    1,  374,    2, 0x08 /* Private */,
      71,    1,  377,    2, 0x08 /* Private */,
      72,    0,  380,    2, 0x08 /* Private */,
      73,    0,  381,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 12,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   20,   21,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Int,   21,   28,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   33,   34,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   36,   37,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   42,   43,   44,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   51,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   55,
    QMetaType::Void, QMetaType::Double,   55,
    QMetaType::Void, QMetaType::Double,   55,
    QMetaType::Void, QMetaType::Double,   55,
    QMetaType::Void, QMetaType::QString,   60,
    QMetaType::Void, QMetaType::QString,   60,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   68,
    QMetaType::Void, QMetaType::QString,   68,
    QMetaType::Void, QMetaType::QString,   68,
    QMetaType::Void, QMetaType::QString,   68,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RadarSerialChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 1: _t->RotarySerialChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 2: _t->typechanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->getRotaryType((*reinterpret_cast< AngleType(*)>(_a[1]))); break;
        case 4: _t->action_adjust(); break;
        case 5: _t->action_output((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->set_measures((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 7: _t->action_lead((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 8: _t->action_write((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->rename_file(); break;
        case 10: _t->on_action_O_triggered(); break;
        case 11: _t->on_pushButtonDetect_clicked(); break;
        case 12: _t->waitUtil((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->waitUtil((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->waitUtil((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->waitUtil(); break;
        case 16: _t->detectProcess((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->on_actionAbout_A_triggered(); break;
        case 18: _t->checkopenslot((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 19: _t->RotarySerialDataRechSlot((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 20: _t->wrongdetectoneslot(); break;
        case 21: _t->wrongdetecttwoslot(); break;
        case 22: _t->RadarSerialDataRechSlot2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 23: _t->radar_reselect_slot(); break;
        case 24: _t->rotary_reselect_slot(); break;
        case 25: _t->radar_adjust_fail_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: _t->radar_adjust_success_slot(); break;
        case 27: _t->save_sate_changed_slot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->adjust_fail_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: _t->adjust_success_slot(); break;
        case 30: _t->judge_qualified_slot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->judge_disqualification((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 32: _t->standard_distance_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 33: _t->speed_changed_slot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 34: _t->slotRotaryAddPort((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 35: _t->slotRadarsAddPort((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 36: _t->onButtonMinClicked(); break;
        case 37: _t->onButtonRestoreClicked(); break;
        case 38: _t->onButtonMaxClicked(); break;
        case 39: _t->onButtonCloseClicked(); break;
        case 40: _t->on_pushButton_refresh_clicked(); break;
        case 41: _t->on_comboBoxRotary_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 42: _t->on_comboType_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 43: _t->on_lineedit_Speed_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 44: _t->on_comboBoxRadars_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 45: _t->ReceiveRadarInfo(); break;
        case 46: _t->on_BtnGenerateReport_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
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
            using _t = void (MainWindow::*)(const QString & , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::RadarSerialChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::RotarySerialChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::typechanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(AngleType & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::getRotaryType)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::action_adjust)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::action_output)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QList<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::set_measures)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(float , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::action_lead)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::action_write)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::rename_file)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::RadarSerialChanged(const QString & _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::RotarySerialChanged(const QString & _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::typechanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::getRotaryType(AngleType & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::action_adjust()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::action_output(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::set_measures(QList<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::action_lead(float _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::action_write(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::rename_file()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
