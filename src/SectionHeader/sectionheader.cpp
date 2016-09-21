#include "SectionHeader/sectionheader.h"

WORD SectionHeader::getNumberOfSection()
{
    return numberOfSection;
}

void SectionHeader::setNumberOfSection(WORD value)
{
    numberOfSection = value;
}

void SectionHeader::fillSections()
{
    free(sections);
    sections = (char**)malloc(numberOfSection * sizeof(char*));

    for (int i = 0; i < numberOfSection; ++i)
      sections[i] = (char*)pointer + i*(8*sizeof(BYTE) + 2*sizeof(WORD) + 7*sizeof(DWORD));
}

int SectionHeader::defSection(DWORD rva)
{
    for (int i = 0; i < numberOfSection; ++i)
    {
        DWORD start = getVirtualAddress(i);                         //  def border section
        DWORD end = start + ALIGN_UP(getVirtualSize(i), sectionAligment);

        if(rva >= start && rva < end)
            return i;
    }
    return -1;
}

char* SectionHeader::getName(int index)
{
    return sections[index];
}

DWORD SectionHeader::getVirtualAddress(uint16_t index)
{
    return READ_DWORD(sections[index] + 8*sizeof(BYTE) + sizeof(DWORD));
}


DWORD SectionHeader::getVirtualSize(int index)
{
    return READ_DWORD(sections[index] + 8*sizeof(BYTE));
}

DWORD SectionHeader::getSizeOfRawData(int index)
{
    return READ_DWORD(sections[index] + 8*sizeof(BYTE) + 2*sizeof(DWORD));
}

DWORD SectionHeader::getPointerToRawData(int index)
{
    return READ_DWORD(sections[index] + 8*sizeof(BYTE) + 3*sizeof(DWORD));
}

DWORD SectionHeader::getSectionAlignment()
{
    return sectionAligment;
}

void SectionHeader::setSectionAlignment(DWORD value)
{
    sectionAligment = value;
}
