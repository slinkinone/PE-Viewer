#include "Common/pefile.h"

PEfile::PEfile(char *path)
{
    loader = new PEloader(path);

    if(loader->getState() == 0)
    {
        buf = loader->getBuf();

        state = check();
        if(state == 0)
            initAll();
    }
    else state = -1;
}

int PEfile::check()
{
    if (READ_WORD(buf) != 0x5A4D)
        return 1;

    if (READ_DWORD(buf + READ_DWORD(buf + 30*sizeof(WORD))) != 0x4550)
        return 2;

    return 0;
}

int PEfile::getState()
{
    return state;
}

void PEfile::initDosHead()
{
    dosHead = new DosHeader(buf);
}

void PEfile::initNtHead()
{
    ntHead = new NTheader(
                buf + READ_DWORD(buf + 30*sizeof(WORD))                                                 //  buf + dosHead->getE_lfanew()
                );
}

void PEfile::initFileHead()
{
    fileHead = new FileHeader(
                buf + READ_DWORD(buf + 30*sizeof(WORD))                                                 //  ntHeader + sizeof(DWORD)
                        + sizeof(DWORD)
                );
}

void PEfile::initOptHead()
{
    optHead = new OptionalHeader(
                buf + READ_DWORD(buf + 30 * sizeof(WORD))                                               //  fHead + 3*sizeof(DWORD) + 4*sizeof(WORD)
                    + sizeof(DWORD) + 3*sizeof(DWORD) + 4*sizeof(WORD)
                );
}

void PEfile::initDataDir()
{
    dataDir = new DataDirectory(
                buf + READ_DWORD(buf + 30 * sizeof(WORD))                                               //  optHead + 9 * sizeof(WORD) + 2 * sizeof(BYTE) + 19 * sizeof(DWORD)
                    + sizeof(DWORD) + 3*sizeof(DWORD) + 4*sizeof(WORD)
                    + 9 * sizeof(WORD) + 2 * sizeof(BYTE) + 19 * sizeof(DWORD)
                );

    dataDir->fillDirs();
}

void PEfile::initSecHead()
{
    secHead = new SectionHeader(
                buf + READ_DWORD(buf + 30 * sizeof(WORD))
                    + sizeof(DWORD) + 3*sizeof(DWORD) + 4*sizeof(WORD)
                    + 9 * sizeof(WORD) + 2 * sizeof(BYTE) + 19 * sizeof(DWORD) + 16 * (2 * sizeof(DWORD))   //  optHead +  9 * sizeof(WORD) + 2 * sizeof(BYTE) + 19 * sizeof(DWORD) + 16 * (2 * sizeof(DWORD))
                , optHead->getSectionAlignment());

    secHead->setNumberOfSection(fileHead->getNumberOfSections());
    secHead->fillSections();
}

void PEfile::initImpTable()
{
    int indexSection = secHead->defSection(dataDir->getVirtualAddress(1));
    impTable = new ImportTable(
                    buf + dataDir->getVirtualAddress(1) - secHead->getVirtualAddress(indexSection) + secHead->getPointerToRawData(indexSection)
                );
    impTable->fillTable();
}

DWORD PEfile::rvaToOff(DWORD rva)
{
    int indexSection = secHead->defSection(rva);
    if(indexSection != -1)
        return rva - secHead->getVirtualAddress(indexSection) + secHead->getPointerToRawData(indexSection);
    else
        return 0;
}

const char* PEfile::getPointerThunkData(uint32_t index)
{
    return buf + rvaToOff(impTable->getFirstThunk(index));                                                  // IMAGE_THUNK_DATA
}

void PEfile::initAll()
{
    initDosHead();
    initNtHead();
    initFileHead();
    initOptHead();
    initDataDir();
    initSecHead();
    initImpTable();
}

PEfile::~PEfile()
{
    if(state == -1)
        return;

    delete loader;
    delete dosHead;
    delete ntHead;
    delete fileHead;
    delete optHead;
    delete dataDir;
    delete secHead;
    delete impTable;
}
