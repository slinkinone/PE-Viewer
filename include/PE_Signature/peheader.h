#ifndef PEHEADER
#define PEHEADER

#include <cstdio>
#include <malloc.h>
#include "datareader.h"

class Header
{
protected:
    const char* pointer;

public:
    Header() : pointer(NULL) {}
    Header(const char* pBuf);
    virtual ~Header() {}
};

#endif // PEHEADER
