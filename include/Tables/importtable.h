#ifndef IMPORTTABLE
#define IMPORTTABLE

#include "PE_Signature/peheader.h"

#define SIZE_ROW_IMPORT_TABLE 5*sizeof(DWORD)

class ImportTable : protected Header
{
public:
    ImportTable() : Header(NULL), _count(0) {}
    ImportTable(const char* pBuf) : Header(pBuf), _count(0) {}
    ~ImportTable() {}

    DWORD GetCount();
    void FillTable();

    DWORD GetOriginalFirstThunk(uint32_t index);
    DWORD GetTimeDateStamp(uint32_t index);
    DWORD GetForwarderChain(uint32_t index);
    DWORD GetName(uint32_t index);
    DWORD GetFirstThunk(uint32_t index);

private:
    uint32_t _count;
};

#endif // IMPORTTABLE
