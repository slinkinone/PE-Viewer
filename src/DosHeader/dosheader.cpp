#include "DosHeader/dosheader.h"

WORD DosHeader::getE_magic()
{
    return READ_WORD(pointer);
}

DWORD DosHeader::getE_lfanew()
{
    return READ_DWORD(pointer + 30 * sizeof(WORD));
}
