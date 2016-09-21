#include "ntheader.h"

DWORD NTheader::getSignature()
{
    return READ_DWORD(pointer);
}
