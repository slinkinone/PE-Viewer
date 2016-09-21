#ifndef PEPRINTER
#define PEPRINTER

#include "pefile.h"
using ::std::hex;

class PEprinter : public PEfile
{
public:
    PEprinter() : PEfile() {}
    PEprinter(char* path) : PEfile(path) {}

    void setFormat(uint8_t type);

    void printSections();
    void printAddressOfEntryPoint();
    void printImageBase();

    void printImportTable();
    void printError();
};

#endif // PEPRINTER
