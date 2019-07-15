#include "Common/peloader.h"

PEloader::PEloader(char *path)
{
    this->_path = (char*)malloc(strlen(path));
    strcpy(this->_path, path);
    _state = Read();
}

PEloader::~PEloader()
{
    free(_path);
    free(_buf);
}

int PEloader::Read()
{
    int state;
    struct stat st;

    if ((state = stat(_path, &st))!=0)
    {
        free(_buf);
        _buf = NULL;
        this->_state = state;
    }

    _buf = (char*)malloc(st.st_size);

    std::ifstream f(_path, std::ifstream::binary);
    f.read(_buf, st.st_size);
    f.close();

    return state;
}

const char* PEloader::GetBuf() const
{
    return _buf;
}

int PEloader::GetState()
{
    return _state;
}
