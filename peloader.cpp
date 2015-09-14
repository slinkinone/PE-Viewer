#include "peloader.h"

PEloader::PEloader(char *path)
{
    this->path = (char*)malloc(strlen(path));
    strcpy(this->path, path);
    state = read();
}

PEloader::~PEloader()
{
    free(path);
    free(buf);
}

int PEloader::read()
{
    int state;
    struct stat st;

    if ((state = stat(path, &st))!=0)
    {
        free(buf);
        buf = NULL;
        this->state = state;
    }

    buf = (char*)malloc(st.st_size);

    std::ifstream f(path, std::ifstream::binary);
    f.read(buf, st.st_size);
    f.close();

    return state;
}

const char* PEloader::getBuf() const
{
    return buf;
}

int PEloader::getState()
{
    return state;
}