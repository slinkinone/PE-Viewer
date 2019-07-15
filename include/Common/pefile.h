#ifndef PEFILE
#define PEFILE

#include <iostream>
#include <malloc.h>
#include <string.h>

#include "datareader.h"
#include "NT_Header/ntheader.h"
#include "peloader.h"
#include "DosHeader/dosheader.h"
#include "NT_Header/FileHeader/fileheader.h"
#include "NT_Header/OptionalHeader/optionalheader.h"
#include "DataDirectory/datadirectory.h"
#include "SectionHeader/sectionheader.h"
#include "Tables/importtable.h"

class PEfile
{
public:
    PEfile() : _state(-1), _loader (NULL), _dosHead(NULL), _ntHead(NULL), _fileHead(NULL), _optHead(NULL),
                _dataDir(NULL), _secHead(NULL), _impTable(NULL) {}
    PEfile(char* path);
    ~PEfile();

    void Reload(char* path);
    int GetState();

    void InitAll();

    int Check();
    const char* GetPointerThunkData(uint32_t index);
    DWORD RvaToOff(DWORD rva);

private:
    void InitDosHead();
    void InitNtHead();
    void InitFileHead();
    void InitOptHead();
    void InitDataDir();
    void InitSecHead();
    void InitImpTable();

protected:
    const char* _buf;

    PEloader* _loader;
    DosHeader* _dosHead;
    NTheader* _ntHead;
    FileHeader* _fileHead;
    OptionalHeader* _optHead;
    DataDirectory* _dataDir;
    SectionHeader* _secHead;
    ImportTable* _impTable;

private:
    int _state;
};

#endif // PEFILE
