#include "DataDirectory/datadirectory.h"

void DataDirectory::fillDirs()
{
    for (int i = 0; i < numberOfDirs; ++i)
        dirs[i] = (char*)pointer + i*(2*sizeof(DWORD));
}

DWORD DataDirectory::getVirtualAddress(uint8_t index)
{
    return READ_DWORD(dirs[index]);
}

DWORD DataDirectory::getSize(uint8_t index)
{
    return READ_DWORD(dirs[index] + sizeof(DWORD));
}
