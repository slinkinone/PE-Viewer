#ifndef OPTIONALHEADER
#define OPTIONALHEADER

#include "PE_Signature/peheader.h"

class OptionalHeader : protected Header
{
public:
    OptionalHeader() : Header(NULL) {}
    OptionalHeader(const char* pBuf) : Header(pBuf) {}
    ~OptionalHeader() {}

    DWORD GetAddressOfEntryPoint();
    DWORD GetImageBase();
    DWORD GetSectionAlignment();
};

#endif // OPTIONALHEADER
