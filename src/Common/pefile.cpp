#include "Common/pefile.h"

PEfile::PEfile(char *path)
{
    _loader = new PEloader(path);

    if(_loader->GetState() == 0)
    {
        _buf = _loader->GetBuf();

        InitFileHead();
        if(_fileHead->GetMachine() == 0x8664)
        {
            _state = 3;
            return;
        }

        _state = Check();
        if(_state == 0)
            InitAll();
    }
    else _state = -1;
}

int PEfile::Check()
{
    if (READ_WORD(_buf) != 0x5A4D)
        return 1;

    if (READ_DWORD(_buf + READ_DWORD(_buf + 30*sizeof(WORD))) != 0x4550)
        return 2;

    return 0;
}

int PEfile::GetState()
{
    return _state;
}

void PEfile::InitDosHead()
{
    _dosHead = new DosHeader(_buf);
}

void PEfile::InitNtHead()
{
    _ntHead = new NTheader(
                _buf + READ_DWORD(_buf + 30*sizeof(WORD))                                                 //  buf + dosHead->getE_lfanew()
                );
}

void PEfile::InitFileHead()
{
    _fileHead = new FileHeader(
                _buf + READ_DWORD(_buf + 30*sizeof(WORD))                                                 //  ntHeader + sizeof(DWORD)
                        + sizeof(DWORD)
                );
}

void PEfile::InitOptHead()
{
    _optHead = new OptionalHeader(
                _buf + READ_DWORD(_buf + 30 * sizeof(WORD))                                               //  fHead + 3*sizeof(DWORD) + 4*sizeof(WORD)
                    + sizeof(DWORD) + 3*sizeof(DWORD) + 4*sizeof(WORD)
                );
}

void PEfile::InitDataDir()
{
    _dataDir = new DataDirectory(
                _buf + READ_DWORD(_buf + 30 * sizeof(WORD))                                               //  optHead + 9 * sizeof(WORD) + 2 * sizeof(BYTE) + 19 * sizeof(DWORD)
                    + sizeof(DWORD) + 3*sizeof(DWORD) + 4*sizeof(WORD)
                    + 9 * sizeof(WORD) + 2 * sizeof(BYTE) + 19 * sizeof(DWORD)
                );

    _dataDir->FillDirs();
}

void PEfile::InitSecHead()
{
    _secHead = new SectionHeader(
                _buf + READ_DWORD(_buf + 30 * sizeof(WORD))
                    + sizeof(DWORD) + 3*sizeof(DWORD) + 4*sizeof(WORD)
                    + 9 * sizeof(WORD) + 2 * sizeof(BYTE) + 19 * sizeof(DWORD) + 16 * (2 * sizeof(DWORD))   //  optHead +  9 * sizeof(WORD) + 2 * sizeof(BYTE) + 19 * sizeof(DWORD) + 16 * (2 * sizeof(DWORD))
                , _optHead->GetSectionAlignment());

    _secHead->SetNumberOfSection(_fileHead->GetNumberOfSections());
    _secHead->FillSections();
}

void PEfile::InitImpTable()
{
    int indexSection = _secHead->DefSection(_dataDir->GetVirtualAddress(1));
    _impTable = new ImportTable(
                    _buf + _dataDir->GetVirtualAddress(1)
                    - _secHead->GetVirtualAddress(indexSection)
                    + _secHead->GetPointerToRawData(indexSection)
                );
    _impTable->FillTable();
}

DWORD PEfile::RvaToOff(DWORD rva)
{
    int indexSection = _secHead->DefSection(rva);
    if(indexSection != -1)
        return rva - _secHead->GetVirtualAddress(indexSection)
                    + _secHead->GetPointerToRawData(indexSection);
    else
        return 0;
}

const char* PEfile::GetPointerThunkData(uint32_t index)
{
    return _buf + RvaToOff(_impTable->GetFirstThunk(index));                                                  // IMAGE_THUNK_DATA
}

void PEfile::InitAll()
{
    InitDosHead();
    InitNtHead();
    InitFileHead();
    InitOptHead();
    InitDataDir();
    InitSecHead();
    InitImpTable();
}

PEfile::~PEfile()
{
    if(_state != 0)
        return;

    delete _loader;
    delete _dosHead;
    delete _ntHead;
    delete _fileHead;
    delete _optHead;
    delete _dataDir;
    delete _secHead;
    delete _impTable;
}
