#include "NT_Header/ntheader.h"

DWORD NTheader::getSignature()
{
    return READ_DWORD(pointer);
}
