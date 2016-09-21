#include "fileheader.h"

WORD FileHeader::getMachine()
{
    return READ_WORD(pointer);
}

WORD FileHeader::getNumberOfSections()
{
    return READ_WORD(pointer + sizeof(WORD));
}