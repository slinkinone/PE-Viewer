#ifndef SECTIONHEADER
#define SECTIONHEADER

#include "PE_Signature/peheader.h"

class SectionHeader : protected Header
{
public:
    SectionHeader() : Header(NULL), _sectionAligment(0), _numberOfSection(0), _sections(NULL) {}
    SectionHeader(const char* pBuf, DWORD secAlig) : Header(pBuf), _sectionAligment(secAlig), _numberOfSection(0), _sections(NULL) {}
    ~SectionHeader() {}

    WORD GetNumberOfSection();
    void SetNumberOfSection(WORD value);
    void FillSections();
    int DefSection(DWORD rva);

    char* GetName(int index);
    DWORD GetVirtualAddress(uint16_t index);
    DWORD GetVirtualSize(int index);
    DWORD GetSizeOfRawData(int index);
    DWORD GetPointerToRawData(int index);
    DWORD GetSectionAlignment();
    void SetSectionAlignment(DWORD value);

private:
    DWORD _sectionAligment;
    WORD _numberOfSection;
    char** _sections;
};

#endif // SECTIONHEADER
