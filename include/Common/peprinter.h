#ifndef PEPRINTER
#define PEPRINTER

#include "pefile.h"
using ::std::hex;

class PEprinter : public PEfile
{
public:
    PEprinter() : PEfile() {}
    PEprinter(char* path) : PEfile(path) {}

    void SetFormat(uint8_t type);

    void PrintSections();
    void PrintAddressOfEntryPoint();
    void PrintImageBase();

    void PrintImportTable();
    void PrintError();
};

#endif // PEPRINTER
