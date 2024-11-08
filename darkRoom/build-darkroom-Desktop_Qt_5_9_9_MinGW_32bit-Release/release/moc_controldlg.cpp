/****************************************************************************
** Meta object code from reading C++ file 'controldlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Darkroom_mz_ok_0628/controldlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controldlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_controldlg_t {
    QByteArrayData data[77];
    char stringdata0[1319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_controldlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_controldlg_t qt_meta_stringdata_controldlg = {
    {
QT_MOC_LITERAL(0, 0, 10), // "controldlg"
QT_MOC_LITERAL(1, 11, 9), // "action_cw"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "spd"
QT_MOC_LITERAL(4, 26, 6), // "target"
QT_MOC_LITERAL(5, 33, 10), // "action_ccw"
QT_MOC_LITERAL(6, 44, 11), // "action_stop"
QT_MOC_LITERAL(7, 56, 12), // "action_reset"
QT_MOC_LITERAL(8, 69, 11), // "action_lead"
QT_MOC_LITERAL(9, 81, 18), // "action_calibration"
QT_MOC_LITERAL(10, 100, 11), // "typechanged"
QT_MOC_LITERAL(11, 112, 4), // "type"
QT_MOC_LITERAL(12, 117, 14), // "radar_reselect"
QT_MOC_LITERAL(13, 132, 15), // "rotary_reselect"
QT_MOC_LITERAL(14, 148, 18), // "RadarSerialChanged"
QT_MOC_LITERAL(15, 167, 8), // "portname"
QT_MOC_LITERAL(16, 176, 8), // "baudrate"
QT_MOC_LITERAL(17, 185, 8), // "databits"
QT_MOC_LITERAL(18, 194, 8), // "stopbits"
QT_MOC_LITERAL(19, 203, 6), // "parity"
QT_MOC_LITERAL(20, 210, 19), // "RotarySerialChanged"
QT_MOC_LITERAL(21, 230, 19), // "availableportdetect"
QT_MOC_LITERAL(22, 250, 18), // "save_state_changed"
QT_MOC_LITERAL(23, 269, 6), // "tosave"
QT_MOC_LITERAL(24, 276, 17), // "precision_changed"
QT_MOC_LITERAL(25, 294, 9), // "pricision"
QT_MOC_LITERAL(26, 304, 15), // "radarid_changed"
QT_MOC_LITERAL(27, 320, 2), // "id"
QT_MOC_LITERAL(28, 323, 21), // "action_output_changed"
QT_MOC_LITERAL(29, 345, 6), // "output"
QT_MOC_LITERAL(30, 352, 16), // "distance_changed"
QT_MOC_LITERAL(31, 369, 8), // "distance"
QT_MOC_LITERAL(32, 378, 13), // "speed_changed"
QT_MOC_LITERAL(33, 392, 5), // "speed"
QT_MOC_LITERAL(34, 398, 14), // "action_get_uid"
QT_MOC_LITERAL(35, 413, 18), // "sinalRotaryAddPort"
QT_MOC_LITERAL(36, 432, 10), // "t_qstrPort"
QT_MOC_LITERAL(37, 443, 18), // "sinalRadarsAddPort"
QT_MOC_LITERAL(38, 462, 21), // "availableportnameslot"
QT_MOC_LITERAL(39, 484, 14), // "QList<QString>"
QT_MOC_LITERAL(40, 499, 5), // "ports"
QT_MOC_LITERAL(41, 505, 24), // "RotarySerialDataRechSlot"
QT_MOC_LITERAL(42, 530, 4), // "val1"
QT_MOC_LITERAL(43, 535, 4), // "val2"
QT_MOC_LITERAL(44, 540, 4), // "val3"
QT_MOC_LITERAL(45, 545, 13), // "send_uid_slot"
QT_MOC_LITERAL(46, 559, 3), // "uid"
QT_MOC_LITERAL(47, 563, 24), // "slotChangeBoxRotaryIndex"
QT_MOC_LITERAL(48, 588, 4), // "arg1"
QT_MOC_LITERAL(49, 593, 24), // "slotChangeBoxRadarsIndex"
QT_MOC_LITERAL(50, 618, 19), // "slotChangeComboType"
QT_MOC_LITERAL(51, 638, 15), // "slotChangeSpeed"
QT_MOC_LITERAL(52, 654, 18), // "slotChangePosition"
QT_MOC_LITERAL(53, 673, 37), // "on_comboBoxRadars_currentInde..."
QT_MOC_LITERAL(54, 711, 8), // "selected"
QT_MOC_LITERAL(55, 720, 37), // "on_comboBoxRotary_currentInde..."
QT_MOC_LITERAL(56, 758, 32), // "on_comboType_currentIndexChanged"
QT_MOC_LITERAL(57, 791, 19), // "on_buttonCw_clicked"
QT_MOC_LITERAL(58, 811, 25), // "on_pushButton_Ccw_clicked"
QT_MOC_LITERAL(59, 837, 26), // "on_pushButton_lead_clicked"
QT_MOC_LITERAL(60, 864, 27), // "on_pushButton_reset_clicked"
QT_MOC_LITERAL(61, 892, 33), // "on_pushButton_calibration_cli..."
QT_MOC_LITERAL(62, 926, 26), // "on_pushButton_stop_clicked"
QT_MOC_LITERAL(63, 953, 29), // "on_pushButton_refresh_clicked"
QT_MOC_LITERAL(64, 983, 18), // "onButtonMinClicked"
QT_MOC_LITERAL(65, 1002, 22), // "onButtonRestoreClicked"
QT_MOC_LITERAL(66, 1025, 18), // "onButtonMaxClicked"
QT_MOC_LITERAL(67, 1044, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(68, 1065, 28), // "on_pushButton_output_clicked"
QT_MOC_LITERAL(69, 1094, 27), // "on_pushButton_noput_clicked"
QT_MOC_LITERAL(70, 1122, 31), // "on_lineEdit_radarID_textChanged"
QT_MOC_LITERAL(71, 1154, 33), // "on_lineEdit_precision_textCha..."
QT_MOC_LITERAL(72, 1188, 33), // "on_checkBox_saveData_stateCha..."
QT_MOC_LITERAL(73, 1222, 7), // "checked"
QT_MOC_LITERAL(74, 1230, 32), // "on_lineEdit_distance_textChanged"
QT_MOC_LITERAL(75, 1263, 29), // "on_lineedit_Speed_textChanged"
QT_MOC_LITERAL(76, 1293, 25) // "on_pushButton_uid_clicked"

    },
    "controldlg\0action_cw\0\0spd\0target\0"
    "action_ccw\0action_stop\0action_reset\0"
    "action_lead\0action_calibration\0"
    "typechanged\0type\0radar_reselect\0"
    "rotary_reselect\0RadarSerialChanged\0"
    "portname\0baudrate\0databits\0stopbits\0"
    "parity\0RotarySerialChanged\0"
    "availableportdetect\0save_state_changed\0"
    "tosave\0precision_changed\0pricision\0"
    "radarid_changed\0id\0action_output_changed\0"
    "output\0distance_changed\0distance\0"
    "speed_changed\0speed\0action_get_uid\0"
    "sinalRotaryAddPort\0t_qstrPort\0"
    "sinalRadarsAddPort\0availableportnameslot\0"
    "QList<QString>\0ports\0RotarySerialDataRechSlot\0"
    "val1\0val2\0val3\0send_uid_slot\0uid\0"
    "slotChangeBoxRotaryIndex\0arg1\0"
    "slotChangeBoxRadarsIndex\0slotChangeComboType\0"
    "slotChangeSpeed\0slotChangePosition\0"
    "on_comboBoxRadars_currentIndexChanged\0"
    "selected\0on_comboBoxRotary_currentIndexChanged\0"
    "on_comboType_currentIndexChanged\0"
    "on_buttonCw_clicked\0on_pushButton_Ccw_clicked\0"
    "on_pushButton_lead_clicked\0"
    "on_pushButton_reset_clicked\0"
    "on_pushButton_calibration_clicked\0"
    "on_pushButton_stop_clicked\0"
    "on_pushButton_refresh_clicked\0"
    "onButtonMinClicked\0onButtonRestoreClicked\0"
    "onButtonMaxClicked\0onButtonCloseClicked\0"
    "on_pushButton_output_clicked\0"
    "on_pushButton_noput_clicked\0"
    "on_lineEdit_radarID_textChanged\0"
    "on_lineEdit_precision_textChanged\0"
    "on_checkBox_saveData_stateChanged\0"
    "checked\0on_lineEdit_distance_textChanged\0"
    "on_lineedit_Speed_textChanged\0"
    "on_pushButton_uid_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_controldlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      51,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      21,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  269,    2, 0x06 /* Public */,
       5,    2,  274,    2, 0x06 /* Public */,
       6,    0,  279,    2, 0x06 /* Public */,
       7,    0,  280,    2, 0x06 /* Public */,
       8,    2,  281,    2, 0x06 /* Public */,
       9,    1,  286,    2, 0x06 /* Public */,
      10,    1,  289,    2, 0x06 /* Public */,
      12,    0,  292,    2, 0x06 /* Public */,
      13,    0,  293,    2, 0x06 /* Public */,
      14,    5,  294,    2, 0x06 /* Public */,
      20,    5,  305,    2, 0x06 /* Public */,
      21,    0,  316,    2, 0x06 /* Public */,
      22,    1,  317,    2, 0x06 /* Public */,
      24,    1,  320,    2, 0x06 /* Public */,
      26,    1,  323,    2, 0x06 /* Public */,
      28,    1,  326,    2, 0x06 /* Public */,
      30,    1,  329,    2, 0x06 /* Public */,
      32,    1,  332,    2, 0x06 /* Public */,
      34,    0,  335,    2, 0x06 /* Public */,
      35,    1,  336,    2, 0x06 /* Public */,
      37,    1,  339,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      38,    1,  342,    2, 0x0a /* Public */,
      41,    3,  345,    2, 0x0a /* Public */,
      45,    1,  352,    2, 0x0a /* Public */,
      47,    1,  355,    2, 0x0a /* Public */,
      49,    1,  358,    2, 0x0a /* Public */,
      50,    1,  361,    2, 0x0a /* Public */,
      51,    1,  364,    2, 0x0a /* Public */,
      52,    1,  367,    2, 0x0a /* Public */,
      53,    1,  370,    2, 0x0a /* Public */,
      55,    1,  373,    2, 0x0a /* Public */,
      56,    1,  376,    2, 0x0a /* Public */,
      57,    0,  379,    2, 0x0a /* Public */,
      58,    0,  380,    2, 0x0a /* Public */,
      59,    0,  381,    2, 0x0a /* Public */,
      60,    0,  382,    2, 0x0a /* Public */,
      61,    0,  383,    2, 0x0a /* Public */,
      62,    0,  384,    2, 0x0a /* Public */,
      63,    0,  385,    2, 0x0a /* Public */,
      64,    0,  386,    2, 0x08 /* Private */,
      65,    0,  387,    2, 0x08 /* Private */,
      66,    0,  388,    2, 0x08 /* Private */,
      67,    0,  389,    2, 0x08 /* Private */,
      68,    0,  390,    2, 0x08 /* Private */,
      69,    0,  391,    2, 0x08 /* Private */,
      70,    1,  392,    2, 0x08 /* Private */,
      71,    1,  395,    2, 0x08 /* Private */,
      72,    1,  398,    2, 0x08 /* Private */,
      74,    1,  401,    2, 0x08 /* Private */,
      75,    1,  404,    2, 0x08 /* Private */,
      76,    0,  407,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    3,    4,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    3,    4,
    QMetaType::Void, QMetaType::Float,    4,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   17,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   17,   18,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Double,   25,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Double,   31,
    QMetaType::Void, QMetaType::Double,   33,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   36,
    QMetaType::Void, QMetaType::QString,   36,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 39,   40,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   42,   43,   44,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::Int,   73,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void, QMetaType::QString,   48,
    QMetaType::Void,

       0        // eod
};

void controldlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        controldlg *_t = static_cast<controldlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->action_cw((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: _t->action_ccw((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 2: _t->action_stop(); break;
        case 3: _t->action_reset(); break;
        case 4: _t->action_lead((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 5: _t->action_calibration((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->typechanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->radar_reselect(); break;
        case 8: _t->rotary_reselect(); break;
        case 9: _t->RadarSerialChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 10: _t->RotarySerialChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 11: _t->availableportdetect(); break;
        case 12: _t->save_state_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->precision_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->radarid_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->action_output_changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->distance_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->speed_changed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->action_get_uid(); break;
        case 19: _t->sinalRotaryAddPort((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->sinalRadarsAddPort((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->availableportnameslot((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 22: _t->RotarySerialDataRechSlot((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 23: _t->send_uid_slot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->slotChangeBoxRotaryIndex((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 25: _t->slotChangeBoxRadarsIndex((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 26: _t->slotChangeComboType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: _t->slotChangeSpeed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: _t->slotChangePosition((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: _t->on_comboBoxRadars_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->on_comboBoxRotary_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->on_comboType_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->on_buttonCw_clicked(); break;
        case 33: _t->on_pushButton_Ccw_clicked(); break;
        case 34: _t->on_pushButton_lead_clicked(); break;
        case 35: _t->on_pushButton_reset_clicked(); break;
        case 36: _t->on_pushButton_calibration_clicked(); break;
        case 37: _t->on_pushButton_stop_clicked(); break;
        case 38: _t->on_pushButton_refresh_clicked(); break;
        case 39: _t->onButtonMinClicked(); break;
        case 40: _t->onButtonRestoreClicked(); break;
        case 41: _t->onButtonMaxClicked(); break;
        case 42: _t->onButtonCloseClicked(); break;
        case 43: _t->on_pushButton_output_clicked(); break;
        case 44: _t->on_pushButton_noput_clicked(); break;
        case 45: _t->on_lineEdit_radarID_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 46: _t->on_lineEdit_precision_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 47: _t->on_checkBox_saveData_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->on_lineEdit_distance_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 49: _t->on_lineedit_Speed_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 50: _t->on_pushButton_uid_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
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
            typedef void (controldlg::*_t)(float , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::action_cw)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(float , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::action_ccw)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::action_stop)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::action_reset)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(float , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::action_lead)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::action_calibration)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::typechanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::radar_reselect)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::rotary_reselect)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(const QString & , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::RadarSerialChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(const QString & , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::RotarySerialChanged)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::availableportdetect)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::save_state_changed)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::precision_changed)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::radarid_changed)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::action_output_changed)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::distance_changed)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::speed_changed)) {
                *result = 17;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::action_get_uid)) {
                *result = 18;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::sinalRotaryAddPort)) {
                *result = 19;
                return;
            }
        }
        {
            typedef void (controldlg::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&controldlg::sinalRadarsAddPort)) {
                *result = 20;
                return;
            }
        }
    }
}

const QMetaObject controldlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_controldlg.data,
      qt_meta_data_controldlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *controldlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *controldlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_controldlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int controldlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 51)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 51;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 51)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 51;
    }
    return _id;
}

// SIGNAL 0
void controldlg::action_cw(float _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void controldlg::action_ccw(float _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void controldlg::action_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void controldlg::action_reset()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void controldlg::action_lead(float _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void controldlg::action_calibration(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void controldlg::typechanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void controldlg::radar_reselect()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void controldlg::rotary_reselect()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void controldlg::RadarSerialChanged(const QString & _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void controldlg::RotarySerialChanged(const QString & _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void controldlg::availableportdetect()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void controldlg::save_state_changed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void controldlg::precision_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void controldlg::radarid_changed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void controldlg::action_output_changed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void controldlg::distance_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void controldlg::speed_changed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void controldlg::action_get_uid()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void controldlg::sinalRotaryAddPort(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void controldlg::sinalRadarsAddPort(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
