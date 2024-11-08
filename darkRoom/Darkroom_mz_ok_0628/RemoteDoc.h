#ifndef CREMOTEDOC_H
#define CREMOTEDOC_H
#include "Axis.h"

typedef unsigned char BYTE;
const int G_WriteBufferLength = 12;

class RotaryRemoteDoc
{
public:
    double GetAngle(AngleType type);
    void GetHumanAngle(AngleType type, char *str);
    void GetLimit(AngleType type, EnumDialLimit &limit);
    void SetAngle(AngleType type, double value);
    void SetLimit(AngleType type, EnumDialLimit &limit);

private:
    double _azAngle;
    double _elAngle;
    double _polAngle;
    double _xDistance;
    double _yDistance;
    double _zDistance;
    double _UpAzAngle;

    EnumDialLimit _azLimit;
    EnumDialLimit _elLimit;
    EnumDialLimit _polLimit;
    EnumDialLimit _upPolLimit;
    EnumDialLimit _xLimit;
    EnumDialLimit _yLimit;
    EnumDialLimit _zLimit;

public:
    BYTE m_writeBuffer[G_WriteBufferLength+2];
    void MakeCommand(AngleType type, AxisExecute run, double value1, double value2);
    void ClearCommand();

public:
    RotaryRemoteDoc();
    void InitAngleValue();
    virtual ~RotaryRemoteDoc();
};

class RadarRemoteDoc
{
public:
    void SetXYZ(double x, double y, double z);
    void adjust();
    double GetX();
    double GetY();
    double GetZ();
public:
    RadarRemoteDoc();
private:
    double _x;
    double _y;
    double _z;

public:
    char *m_writeBuffer[G_WriteBufferLength*10];
    void MakeCommand(RadarCommand cmd);
    void ClearCommand();
};

#endif // CREMOTEDOC_H
