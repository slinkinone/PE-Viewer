#ifndef DOSHEADER
#define DOSHEADER

#include "PE_Signature/peheader.h"

class DosHeader : protected Header
{
public:
    DosHeader() : Header(NULL) {}
    DosHeader(const char* pBuf) : Header(pBuf) {}
    ~DosHeader() {}

    WORD GetE_magic();
    DWORD GetE_lfanew();
};

#endif // DOSHEADER
