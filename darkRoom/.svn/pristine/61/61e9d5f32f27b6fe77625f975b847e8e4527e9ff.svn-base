#include "Communicate.h"
#include "RemoteDoc.h"
#include "Spcomm.h"

static BYTE G_Buffer[12];
static BYTE G_Recv[64];

void Communicate::ReceiveData(void *doc, char *buffer, unsigned short BufferLength)
{
    RadarRemoteDoc *pDoc = static_cast<RadarRemoteDoc *>(doc);
    double x=0, y=0, z=0;
    sscanf_s(buffer, "%lf x=%lf,y=%lf\n",&z, &x, &y);
    if(!(x==0 && y==0 && z==0))
        pDoc->SetXYZ(x, y, z);
}

/*转台串口数据解析*/
void Communicate::ReceiveData(void *doc, void *buffer, unsigned short BufferLength, AngleType type)
{
    if(BufferLength > 64)
        BufferLength = 64;
    RotaryRemoteDoc *pDoc = static_cast<RotaryRemoteDoc *>(doc);
    memcpy_s(G_Recv, 64, buffer, BufferLength);
    switch(type)
    {
    case AT_Az:
    case AT_El:
    case AT_Pol: //水平、俯仰、横滚角度解析
        for(int i=0; i<BufferLength; i++)
        {
            if(OnReceiveAT_AzElPol(G_Buffer, G_Recv[i], pDoc) == true)  //数据解析
            {
                return;
            }
        }
        break;
    case AT_X:
    case AT_Y:
    case AT_Z:
        for(int i=0; i<BufferLength; i++)
        {
            if(OnReceiveAT_XYZ(G_Buffer, G_Recv[i], pDoc) == true)
            {
                return;
            }
        }
        break;
    default:
        break;
    }
}

bool Communicate::Checksum(BYTE *buf)
{
    BYTE cs = 0;
    for(int i=0; i<17; ++i)
    {
        cs += buf[i];
    }
    return cs = (BYTE)buf[17];
}

bool testBit(int state, int mask)
{
    return (state & mask) == mask;
}

EnumDialLimit GetLimitState(int limCw, int limCcw){
    EnumDialLimit Lim;
    if(limCw == 1 && limCcw == 1)
        Lim = LIMIT_BOTH;
    else
        Lim = limCw == 1 ? LIMIT_CW : (limCcw == 1 ? LIMIT_CCW : LIMIT_NONE);
    return Lim;
}

bool Communicate::OnReceiveAT_XYZ(BYTE *buffer, BYTE ch, RotaryRemoteDoc *pDoc)
{
    long angle = 0, angle_1 =0, angle_2 = 0;
    for(int i=0; i<18; i++)
    {
        buffer[i] = buffer[i+1];
    }
    buffer[18] = ch;
    if(buffer[0] == 0xFE && buffer[18] == 0xEF)
    {
        if(Checksum(buffer) == false)
            return false;
        double ang = 0.0, ang2 = 0.0;
        int stat = 0;
        angle |= buffer[2]&0xff;
        angle <<= 8;
        angle |= buffer[3]&0xff;
        angle <<=8;
        angle |= buffer[4]&0xff;
        angle <<=8;
        angle |= buffer[5]&0xff;
        pDoc->SetAngle(AT_X, angle/10.0);

        angle = 0;
        angle |= buffer[7]&0xff;
        angle <<= 8;
        angle |= buffer[8]&0xff;
        angle <<= 8;
        angle |= buffer[9]&0xff;
        angle <<= 8;
        angle |= buffer[10]&0xff;
        pDoc->SetAngle(AT_Y, angle/10.0);

        angle = 0;
        angle |= buffer[12]&0xff;
        angle <<= 8;
        angle |= buffer[13]&0xff;
        angle <<= 8;
        angle |= buffer[14]&0xff;
        angle <<= 8;
        angle |= buffer[15]&0xff;
        pDoc->SetAngle(AT_Z, angle/10.0);

        int lims[12] = {
            testBit(buffer[6], 0x01),
            testBit(buffer[6], 0x02),
            testBit(buffer[6], 0x04),
            testBit(buffer[6], 0x08),

            testBit(buffer[11], 0x01),
            testBit(buffer[11], 0x02),
            testBit(buffer[11], 0x04),
            testBit(buffer[11], 0x08),

            testBit(buffer[16], 0x01),
            testBit(buffer[16], 0x02),
            testBit(buffer[16], 0x04),
            testBit(buffer[16], 0x08),
        };

        EnumDialLimit azLim = GetLimitState(lims[0], lims[1]);
        EnumDialLimit elLim = GetLimitState(lims[4], lims[5]);
        EnumDialLimit polLim = GetLimitState(lims[8], lims[9]);

        pDoc->SetLimit(AT_X, azLim);
        pDoc->SetLimit(AT_Y, elLim);
        pDoc->SetLimit(AT_Z, polLim);
        return true;
    }
    return false;
}

bool Communicate::OnReceiveAT_AzElPol(BYTE *buffer, BYTE ch, RotaryRemoteDoc *pDoc)
{
    long angle = 0;
    for(int i=0; i<18; i++)
    {
        buffer[i] = buffer[i+1];
    }
    buffer[18] = ch;
    if(buffer[0] == 0xFE && buffer[18] == 0xEF)
    {
        if(Checksum(buffer) == false)
            return false;

        angle |= buffer[2]&0xff;
        angle <<= 8;
        angle |= buffer[3]&0xff;
        angle <<=8;
        angle |= buffer[4]&0xff;
        angle <<=8;
        angle |= buffer[5]&0xff;
        pDoc->SetAngle(AT_Az, angle/10.0);

        angle = 0;
        angle |= buffer[7]&0xff;
        angle <<= 8;
        angle |= buffer[8]&0xff;
        angle <<= 8;
        angle |= buffer[9]&0xff;
        angle <<= 8;
        angle |= buffer[10]&0xff;
        pDoc->SetAngle(AT_El, angle/10.0);

        angle = 0;
        angle |= buffer[12]&0xff;
        angle <<= 8;
        angle |= buffer[13]&0xff;
        angle <<= 8;
        angle |= buffer[14]&0xff;
        angle <<= 8;
        angle |= buffer[15]&0xff;
        pDoc->SetAngle(AT_Pol, angle/10.0);

        int lims[12] = {
            testBit(buffer[6], 0x01),
            testBit(buffer[6], 0x02),
            testBit(buffer[6], 0x04),
            testBit(buffer[6], 0x08),

            testBit(buffer[11], 0x01),
            testBit(buffer[11], 0x02),
            testBit(buffer[11], 0x04),
            testBit(buffer[11], 0x08),

            testBit(buffer[16], 0x01),
            testBit(buffer[16], 0x02),
            testBit(buffer[16], 0x04),
            testBit(buffer[16], 0x08),
        };

        EnumDialLimit azLim = GetLimitState(lims[0], lims[1]);
        EnumDialLimit elLim = GetLimitState(lims[4], lims[5]);
        EnumDialLimit polLim = GetLimitState(lims[8], lims[9]);

        pDoc->SetLimit(AT_Az, azLim);
        pDoc->SetLimit(AT_El, elLim);
        pDoc->SetLimit(AT_Pol, polLim);
        return true;
    }
    return false;
}

