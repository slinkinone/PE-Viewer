#include "NT_Header/ntheader.h"

DWORD NTheader::GetSignature()
{
    return READ_DWORD(pointer);
}
