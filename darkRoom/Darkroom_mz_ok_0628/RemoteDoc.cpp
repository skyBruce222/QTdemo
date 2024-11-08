#include "RemoteDoc.h"
#include <stdio.h>
#include <memory.h>

void MakeAngle(BYTE *cmd, double angle)
{
    int iang = (int)(angle * 10.0);
    cmd[4] = (iang & 0xff000000) >> 24;
    cmd[5] = (iang & 0x00ff0000) >> 16;
    cmd[6] = (iang & 0x0000ff00) >> 8;
    cmd[7] = (iang & 0x000000ff);
}

void MakeSpd(BYTE *cmd, double spd)
{
    BYTE ispd = (BYTE)spd;
    cmd[8] = ispd;
}

void MakeCheckSum(BYTE *cmd)
{
    BYTE buf = 0;
    for(int i=0; i<9; i++)
    {
        buf += (BYTE)cmd[i];
    }
    cmd[9] = buf;
}

double RotaryRemoteDoc::GetAngle(AngleType type)
{
    double value;
    switch(type)
    {
    case AT_Az:
        value = _azAngle;
        break;
    case AT_El:
        value = _elAngle;
        break;
    case AT_Pol:
        value = _polAngle;
        break;
    case AT_UpPol:
        value = _UpAzAngle;
        break;
    case AT_X:
        value = _xDistance;
        break;
    case AT_Y:
        value = _yDistance;
        break;
    case AT_Z:
        value = _zDistance;
        break;
    default:
        value = 0;
        break;
    }
    return value;
}

void RotaryRemoteDoc::GetHumanAngle(AngleType type, char *str)
{
    switch(type)
    {
    case AT_Az:
        sprintf_s(str, sizeof(str), "%07.2f", _azAngle);
        break;
    case AT_El:
        sprintf_s(str, sizeof(str), "%07.2f", _elAngle);
        break;
    case AT_Pol:
        sprintf_s(str, sizeof(str), "%07.2f", _polAngle);
        break;
    case AT_UpPol:
        sprintf_s(str, sizeof(str), "%07.2f", _UpAzAngle);
        break;
    case AT_X:
        sprintf_s(str, sizeof(str), "%06d", (int)(_xDistance+0.5));
        break;
    case AT_Y:
        sprintf_s(str, sizeof(str), "%06.1f", _yDistance);
        break;
    case AT_Z:
        sprintf_s(str, sizeof(str), "%06.1f", _zDistance);
        break;
    default:
        sprintf_s(str, sizeof(str), "%06.1f", (int)_xDistance);
        break;
    }
}

void RotaryRemoteDoc::GetLimit(AngleType type, EnumDialLimit &limit)
{
    switch(type){
    case AT_Az:
        limit = _azLimit;
        break;
    case AT_El:
        limit = _elLimit;
        break;
    case AT_Pol:
        limit = _polLimit;
        break;
    case AT_UpPol:
        limit = _upPolLimit;
        break;
    case AT_X:
        limit = _xLimit;
        break;
    case AT_Y:
        limit = _yLimit;
        break;
    case AT_Z:
        limit = _zLimit;
        break;
    default:
        limit = LIMIT_NONE;
        break;
    }
}

void RotaryRemoteDoc::SetAngle(AngleType type, double value)
{
    switch(type)
    {
    case AT_Az:
        _azAngle = value;
        break;
    case AT_El:
        _elAngle = value;
        break;
    case AT_Pol:
        _polAngle = value;
        break;
    case AT_UpPol:
        _UpAzAngle = value;
        break;
    case AT_X:
        _xDistance = value;
        break;
    case AT_Y:
        _yDistance = value;
        break;
    case AT_Z:
        _zDistance = value;
        break;
    default:
        break;
    }
}

void RotaryRemoteDoc::SetLimit(AngleType type, EnumDialLimit &limit)
{
    switch(type){
    case AT_Az:
        _azLimit = limit;
        break;
    case AT_El:
        _elLimit = limit;
        break;
    case AT_Pol:
        _polLimit = limit;
        break;
    case AT_UpPol:
        _upPolLimit = limit;
        break;
    case AT_X:
        _xLimit = limit;
        break;
    case AT_Y:
        _yLimit = limit;
        break;
    case AT_Z:
        _zLimit = limit;
        break;
    default:
        break;
    }
}

void RotaryRemoteDoc::MakeCommand(AngleType type, AxisExecute run, double value1, double value2)
{
    BYTE buf[12] = {0xFE, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0xEF, 0xFE};

    switch(run)
    {
    case EXE_Cw:
        if(type == AT_El || type == AT_Y)
            buf[2] = 0x1E;
        else if(type == AT_Az || type == AT_X)
            buf[2] = 0x0E;
        else if(type == AT_Pol || type == AT_Z)
            buf[2] = 0x2E;
        MakeSpd(buf, value1);
        break;

    case EXE_Ccw:
        if(type == AT_El || type == AT_Y)
            buf[2] = 0x1F;
        else if(type == AT_Az || type == AT_X)
            buf[2] = 0x0F;
        else if(type == AT_Pol || type == AT_Z)
            buf[2] = 0x4F;
        MakeSpd(buf, value1);
        break;

    case EXE_Stop:
        if(type == AT_El || type == AT_Y)
            buf[2] = 0x1D;
        else if(type == AT_Az || type == AT_X)
            buf[2] = 0x0D;
        else if(type == AT_Pol || type == AT_Z)
            buf[2] = 0x4D;
        break;

    case EXE_SetSpeed:
        if(type == AT_El || type == AT_Y)
            buf[2] = 0x2F;
        else if(type == AT_Az || type == AT_X)
            buf[2] = 0x3F;
        else if(type == AT_Pol || type == AT_Z)
            buf[2] = 0x5F;
        MakeSpd(buf, value1);
        break;

    case EXE_Calibration:
        if(type == AT_El || type == AT_Y)
            buf[2] = 0x1B;
        else if(type == AT_Az || type == AT_X)
            buf[2] = 0x0B;
        else if(type == AT_Pol || type == AT_Z)
            buf[2] = 0x2B;
        MakeAngle(buf, 0);
        break;

    case EXE_RESET:
        if(type == AT_El || type == AT_Y)
            buf[2] = 0x1C;
        else if(type == AT_Az || type == AT_X)
            buf[2] = 0x0C;
        else if(type == AT_Pol || type == AT_Z)
            buf[2] = 0x2C;
        break;

    case EXE_Lead:
        if(type == AT_El || type == AT_Y)
            buf[2] = 0x1A;
        else if(type == AT_Az || type == AT_X)
            buf[2] = 0x0A;
        else if(type == AT_Pol || type == AT_Z)
            buf[2] = 0x2A;
        MakeSpd(buf, value1);
        MakeAngle(buf, value2);
        break;
    }

    MakeCheckSum(buf);
    for(int i=0; i<G_WriteBufferLength; ++i)
    {
        m_writeBuffer[i] = buf[i];
    }
}

void RotaryRemoteDoc::ClearCommand()
{
    for(int i=0; i<G_WriteBufferLength; i++)
    {
        m_writeBuffer[i] = 0;
    }
}

RotaryRemoteDoc::RotaryRemoteDoc()
{
    InitAngleValue();
}

void RotaryRemoteDoc::InitAngleValue()
{
    _azAngle   = 0;
    _elAngle   = 0;
    _polAngle  = 0;
    _xDistance = 0;
    _yDistance = 0;
    _zDistance = 0;
    _UpAzAngle = 0;

    _azLimit   = LIMIT_NONE;
    _elLimit   = LIMIT_NONE;
    _polLimit  = LIMIT_NONE;
    _upPolLimit = LIMIT_NONE;
    _xLimit    = LIMIT_NONE;
    _yLimit    = LIMIT_NONE;
    _zLimit    = LIMIT_NONE;
}

RotaryRemoteDoc::~RotaryRemoteDoc()
{

}

RadarRemoteDoc::RadarRemoteDoc()
{
    _x = -1; _y = -1;
}

void RadarRemoteDoc::SetXYZ(double x, double y, double z)
{
    _x = x; _y = y; _z = z;
}

void RadarRemoteDoc::adjust()
{

}

double RadarRemoteDoc::GetX()
{
    return _x;
}

double RadarRemoteDoc::GetY()
{
    return _y;
}
double RadarRemoteDoc::GetZ()
{
    return _z;
}

void RadarRemoteDoc::MakeCommand(RadarCommand cmd)
{

}

void RadarRemoteDoc::ClearCommand()
{
    memset(m_writeBuffer, 0, G_WriteBufferLength*10);
}
