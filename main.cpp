#include <iostream>
#include "Common/pefile.h"
#include "Common/peprinter.h"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
        printf("%s\n", "Path to file is not defined");
		return 1;
	}
	else
		printf("%s\n", argv[1]);

	PEprinter pe(argv[1]);
    if(pe.GetState() == 0)
	{
        pe.SetFormat(16);

        pe.PrintAddressOfEntryPoint();
        pe.PrintImageBase();
        pe.PrintSections();
        pe.PrintImportTable();
	}
	else
        pe.PrintError();

	return 0;
}
