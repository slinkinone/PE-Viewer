#include "DataDirectory/datadirectory.h"

void DataDirectory::FillDirs()
{
    for (int i = 0; i < numberOfDirs; ++i)
        _dirs[i] = (char*)pointer + i*(2*sizeof(DWORD));
}

DWORD DataDirectory::GetVirtualAddress(uint8_t index)
{
    return READ_DWORD(_dirs[index]);
}

DWORD DataDirectory::GetSize(uint8_t index)
{
    return READ_DWORD(_dirs[index] + sizeof(DWORD));
}
