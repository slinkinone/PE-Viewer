#ifndef DATADIRECTORY
#define DATADIRECTORY

#include "peheader.h"

const uint8_t numberOfDirs = 16;

class DataDirectory : protected Header
{
protected:
    char* dirs[numberOfDirs];

public:
    DataDirectory() : Header(NULL) {}
    DataDirectory(const char* pBuf) : Header(pBuf) {}
    ~DataDirectory() {}

    void fillDirs();
    DWORD getVirtualAddress(uint8_t index);
    DWORD getSize(uint8_t index);
};

#endif // DATADIRECTORY
