#ifndef DOSHEADER
#define DOSHEADER

#include "peheader.h"

class DosHeader : protected Header
{
public:
    DosHeader() : Header(NULL) {}
    DosHeader(const char* pBuf) : Header(pBuf) {}
    ~DosHeader() {}

    WORD getE_magic();
    DWORD getE_lfanew();
};

#endif // DOSHEADER
