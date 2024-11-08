#ifndef AXIS_H
#define AXIS_H

enum AxisExecute
{
    EXE_Cw,
    EXE_Ccw,
    EXE_Stop,
    EXE_SetSpeed,
    EXE_Calibration,
    EXE_Lead,
    EXE_RESET
};

enum AngleType
{
    AT_Az,
    AT_El,
    AT_Pol,
    AT_UpPol,
    AT_X,
    AT_Y,
    AT_Z
};

enum EnumDialLimit
{
    LIMIT_CW,
    LIMIT_CCW,
    LIMIT_BOTH,
    LIMIT_NONE
};

enum RadarCommand
{
    ADJUST,
    STOP,
    START,
};

#endif // AXIS_H
