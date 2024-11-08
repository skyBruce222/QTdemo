#ifndef COMMUNICATE_H
#define COMMUNICATE_H

#include "Axis.h"
typedef unsigned char BYTE;
class RotaryRemoteDoc;
class Communicate
{
public:
    static void ReceiveData(void *doc, char *buffer, unsigned short BufferLength);
    static void ReceiveData(void *doc, void *buffer, unsigned short BufferLength, AngleType type);
    static bool OnReceiveAT_XYZ(BYTE *buffer, BYTE ch, RotaryRemoteDoc *pDoc);
    static bool OnReceiveAT_AzElPol(BYTE *buffer, BYTE ch, RotaryRemoteDoc *pDoc);
    static bool Checksum(BYTE *buf);
};

#endif // COMMUNICATE_H
