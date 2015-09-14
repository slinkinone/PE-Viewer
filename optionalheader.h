#ifndef OPTIONALHEADER
#define OPTIONALHEADER

#include "peheader.h"

class OptionalHeader : protected Header
{
public:
    OptionalHeader() : Header(NULL) {}
    OptionalHeader(const char* pBuf) : Header(pBuf) {}
    ~OptionalHeader() {}

    DWORD getAddressOfEntryPoint();
    DWORD getImageBase();
    DWORD getSectionAlignment();
};

#endif // OPTIONALHEADER
