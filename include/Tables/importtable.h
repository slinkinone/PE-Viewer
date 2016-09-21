#ifndef IMPORTTABLE
#define IMPORTTABLE

#include "peheader.h"

#define SIZE_ROW_IMPORT_TABLE 5*sizeof(DWORD)

class ImportTable : protected Header
{
private:
    uint32_t count;

public:
    ImportTable() : Header(NULL), count(0) {}
    ImportTable(const char* pBuf) : Header(pBuf), count(0) {}
    ~ImportTable() {}

    DWORD getCount();
    void fillTable();

    DWORD getOriginalFirstThunk(uint32_t index);
    DWORD getTimeDateStamp(uint32_t index);
    DWORD getForwarderChain(uint32_t index);
    DWORD getName(uint32_t index);
    DWORD getFirstThunk(uint32_t index);
};

#endif // IMPORTTABLE
