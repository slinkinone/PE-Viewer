#ifndef DATADIRECTORY
#define DATADIRECTORY

#include "PE_Signature/peheader.h"

const uint8_t numberOfDirs = 16;

class DataDirectory : protected Header
{
public:
    DataDirectory() : Header(NULL) {}
    DataDirectory(const char* pBuf) : Header(pBuf) {}
    ~DataDirectory() {}

    void FillDirs();
    DWORD GetVirtualAddress(uint8_t index);
    DWORD GetSize(uint8_t index);

protected:
    char* _dirs[numberOfDirs];
};

#endif // DATADIRECTORY
