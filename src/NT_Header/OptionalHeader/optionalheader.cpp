#include "OptionalHeader/optionalheader.h"

DWORD OptionalHeader::GetAddressOfEntryPoint()
{
    return READ_DWORD(pointer + sizeof(WORD) + 2*sizeof(BYTE) + 3*sizeof(DWORD));
}

DWORD OptionalHeader::GetImageBase()
{
    return READ_DWORD(pointer + sizeof(WORD) + 2*sizeof(BYTE) + 6*sizeof(DWORD));
}

DWORD OptionalHeader::GetSectionAlignment()
{
    return READ_DWORD(pointer + sizeof(WORD) + 2*sizeof(BYTE) + 7*sizeof(DWORD));
}
