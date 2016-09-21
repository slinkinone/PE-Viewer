#ifndef NTHEADER
#define NTHEADER

#include "peheader.h"

class NTheader : protected Header
{
public:
    NTheader() : Header(NULL) {}
    NTheader(const char* pBuf) : Header(pBuf) {}
    ~NTheader() {}

    DWORD getSignature();

};

#endif // NTHEADER
