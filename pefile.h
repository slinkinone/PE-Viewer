#ifndef PEFILE
#define PEFILE

#include <iostream>
#include <malloc.h>
#include <string.h>

#include "datareader.h"
#include "ntheader.h"
#include "peloader.h"
#include "dosheader.h"
#include "fileheader.h"
#include "optionalheader.h"
#include "datadirectory.h"
#include "sectionheader.h"
#include "importtable.h"

class PEfile
{
private:
    int state;

protected:
    const char* buf;

    PEloader* loader;
    DosHeader* dosHead;
    NTheader* ntHead;
    FileHeader* fileHead;
    OptionalHeader* optHead;
    DataDirectory* dataDir;
    SectionHeader* secHead;
    ImportTable* impTable;

    void initDosHead();
    void initNtHead();
    void initFileHead();
    void initOptHead();
    void initDataDir();
    void initSecHead();
    void initImpTable();

    void initAll();

    int check();
    const char* getPointerThunkData(uint32_t index);
    DWORD rvaToOff(DWORD rva);

public:
    PEfile() : state(-1), loader (NULL), dosHead(NULL), ntHead(NULL), fileHead(NULL), optHead(NULL),
                dataDir(NULL), secHead(NULL), impTable(NULL) {}
    PEfile(char* path);
    ~PEfile();

    void reload(char* path);
    int getState();
};

#endif // PEFILE
