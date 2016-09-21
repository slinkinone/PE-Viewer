#ifndef SECTIONHEADER
#define SECTIONHEADER

#include "PE_Signature/peheader.h"

class SectionHeader : protected Header
{
private:
    DWORD sectionAligment;
    WORD numberOfSection;
    char** sections;

public:
    SectionHeader() : Header(NULL), sectionAligment(0), numberOfSection(0), sections(NULL) {}
    SectionHeader(const char* pBuf, DWORD secAlig) : Header(pBuf), sectionAligment(secAlig), numberOfSection(0), sections(NULL) {}
    ~SectionHeader() {}

    WORD getNumberOfSection();
    void setNumberOfSection(WORD value);
    void fillSections();
    int defSection(DWORD rva);

    char* getName(int index);
    DWORD getVirtualAddress(uint16_t index);
    DWORD getVirtualSize(int index);
    DWORD getSizeOfRawData(int index);
    DWORD getPointerToRawData(int index);
    DWORD getSectionAlignment();
    void setSectionAlignment(DWORD value);

};

#endif // SECTIONHEADER
