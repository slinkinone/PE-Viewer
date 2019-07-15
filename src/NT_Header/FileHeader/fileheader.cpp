#include "NT_Header/FileHeader/fileheader.h"

WORD FileHeader::GetMachine()
{
    return READ_WORD(pointer);
}

WORD FileHeader::GetNumberOfSections()
{
    return READ_WORD(pointer + sizeof(WORD));
}
