#include <iostream>
#include "pefile.h"
#include "peprinter.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("%s\n", "path to file not define");
        return 1;
    }
    else
        printf("%s\n", argv[1]);

    PEprinter pe(argv[1]);
    if(pe.getState() == 0)
    {
        pe.setFormat(16);

        pe.printAddressOfEntryPoint();
        pe.printImageBase();
        pe.printSections();
        pe.printImportTable();
    }
    else
        pe.printError();

    return 0;
}
