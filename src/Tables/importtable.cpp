#include "importtable.h"

DWORD ImportTable::getCount()
{
    return count;
}

void ImportTable::fillTable()
{
    count = 0;
    while (true)
        if(getName(count))
            count++;
        else break;
}

DWORD ImportTable::getOriginalFirstThunk(uint32_t index)
{
    return READ_DWORD(pointer + index*SIZE_ROW_IMPORT_TABLE);
}

DWORD ImportTable::getTimeDateStamp(uint32_t index)
{
    return READ_DWORD(pointer + index*SIZE_ROW_IMPORT_TABLE + 1*sizeof(DWORD));
}

DWORD ImportTable::getForwarderChain(uint32_t index)
{
    return READ_DWORD(pointer + index*SIZE_ROW_IMPORT_TABLE + 2*sizeof(DWORD));
}

DWORD ImportTable::getName(uint32_t index)
{
    return READ_DWORD(pointer + index*SIZE_ROW_IMPORT_TABLE + 3*sizeof(DWORD));
}

DWORD ImportTable::getFirstThunk(uint32_t index)
{
    return READ_DWORD(pointer + index*SIZE_ROW_IMPORT_TABLE + 4*sizeof(DWORD));
}