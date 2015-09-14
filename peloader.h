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

class PEloader
{
private:
    int state;

protected:
    char* path;
    char* buf;

    int read();

public:
    PEloader() : state(-1), path(NULL), buf(NULL) {}
    PEloader(char* path);
    ~PEloader();

    const char* getBuf() const;
    int getState();
};

#endif // PELOADER
