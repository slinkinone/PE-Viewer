#ifndef NTHEADER
#define NTHEADER

#include "PE_Signature/peheader.h"

class NTheader : protected Header
{
public:
    NTheader() : Header(NULL) {}
    NTheader(const char* pBuf) : Header(pBuf) {}
    ~NTheader() {}

    DWORD GetSignature();

};

#endif // NTHEADER
