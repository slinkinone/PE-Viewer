#include "optionalheader.h"

DWORD OptionalHeader::getAddressOfEntryPoint()
{
    return READ_DWORD(pointer + sizeof(WORD) + 2*sizeof(BYTE) + 3*sizeof(DWORD));
}

DWORD OptionalHeader::getImageBase()
{
    return READ_DWORD(pointer + sizeof(WORD) + 2*sizeof(BYTE) + 6*sizeof(DWORD));
}

DWORD OptionalHeader::getSectionAlignment()
{
    return READ_DWORD(pointer + sizeof(WORD) + 2*sizeof(BYTE) + 7*sizeof(DWORD));
}