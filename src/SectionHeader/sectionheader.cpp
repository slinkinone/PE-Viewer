#include "SectionHeader/sectionheader.h"

WORD SectionHeader::GetNumberOfSection()
{
    return _numberOfSection;
}

void SectionHeader::SetNumberOfSection(WORD value)
{
    _numberOfSection = value;
}

void SectionHeader::FillSections()
{
    free(_sections);
    _sections = (char**)malloc(_numberOfSection * sizeof(char*));

    for (int i = 0; i < _numberOfSection; ++i)
      _sections[i] = (char*)pointer + i*(8*sizeof(BYTE) + 2*sizeof(WORD) + 7*sizeof(DWORD));
}

int SectionHeader::DefSection(DWORD rva)
{
    for (int i = 0; i < _numberOfSection; ++i)
    {
        DWORD start = GetVirtualAddress(i);                         //  def border section
        DWORD end = start + ALIGN_UP(GetVirtualSize(i), _sectionAligment);

        if(rva >= start && rva < end)
            return i;
    }
    return -1;
}

char* SectionHeader::GetName(int index)
{
    return _sections[index];
}

DWORD SectionHeader::GetVirtualAddress(uint16_t index)
{
    return READ_DWORD(_sections[index] + 8*sizeof(BYTE) + sizeof(DWORD));
}


DWORD SectionHeader::GetVirtualSize(int index)
{
    return READ_DWORD(_sections[index] + 8*sizeof(BYTE));
}

DWORD SectionHeader::GetSizeOfRawData(int index)
{
    return READ_DWORD(_sections[index] + 8*sizeof(BYTE) + 2*sizeof(DWORD));
}

DWORD SectionHeader::GetPointerToRawData(int index)
{
    return READ_DWORD(_sections[index] + 8*sizeof(BYTE) + 3*sizeof(DWORD));
}

DWORD SectionHeader::GetSectionAlignment()
{
    return _sectionAligment;
}

void SectionHeader::SetSectionAlignment(DWORD value)
{
    _sectionAligment = value;
}
