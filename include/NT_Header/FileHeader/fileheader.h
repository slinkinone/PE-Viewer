#ifndef FILEHEADER
#define FILEHEADER

#include "PE_Signature/peheader.h"

class FileHeader : protected Header
{
public:
    FileHeader() : Header(NULL) {}
    FileHeader(const char* pBuf) : Header(pBuf) {}
    ~FileHeader() {}

    WORD getMachine();
    WORD getNumberOfSections();
};

#endif // FILEHEADER
