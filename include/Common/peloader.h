#ifndef PELOADER
#define PELOADER

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include <sys\stat.h>
#else
    #include <sys/stat.h>
#endif

#include <malloc.h>
#include <string.h>
#include <fstream>

#include "errorcodes.h"

class PEloader
{
public:
    PEloader() : _state(STAT_READ_ERROR), _path(NULL), _buf(NULL) {}
    PEloader(char* _path);
    ~PEloader();

    const char* GetBuf() const;
    int GetState();

private:
    int _state;

protected:
    char* _path;
    char* _buf;

    int Read();
};

#endif // PELOADER
