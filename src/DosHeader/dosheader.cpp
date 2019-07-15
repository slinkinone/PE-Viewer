#include "DosHeader/dosheader.h"

WORD DosHeader::GetE_magic()
{
    return READ_WORD(pointer);
}

DWORD DosHeader::GetE_lfanew()
{
    return READ_DWORD(pointer + 30 * sizeof(WORD));
}
