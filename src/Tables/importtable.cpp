#include "Tables/importtable.h"

DWORD ImportTable::GetCount()
{
    return _count;
}

void ImportTable::FillTable()
{
    _count = 0;
    while (true)
        if(GetName(_count))
            _count++;
        else break;
}

DWORD ImportTable::GetOriginalFirstThunk(uint32_t index)
{
    return READ_DWORD(pointer + index*SIZE_ROW_IMPORT_TABLE);
}

DWORD ImportTable::GetTimeDateStamp(uint32_t index)
{
    return READ_DWORD(pointer + index*SIZE_ROW_IMPORT_TABLE + 1*sizeof(DWORD));
}

DWORD ImportTable::GetForwarderChain(uint32_t index)
{
    return READ_DWORD(pointer + index*SIZE_ROW_IMPORT_TABLE + 2*sizeof(DWORD));
}

DWORD ImportTable::GetName(uint32_t index)
{
    return READ_DWORD(pointer + index*SIZE_ROW_IMPORT_TABLE + 3*sizeof(DWORD));
}

DWORD ImportTable::GetFirstThunk(uint32_t index)
{
    return READ_DWORD(pointer + index*SIZE_ROW_IMPORT_TABLE + 4*sizeof(DWORD));
}
