#include "peprinter.h"

void PEprinter::printError()
{
    int idErr = getState();

    switch (idErr)
    {
        case -1:    printf("stat read error (%d)\n", idErr);
                    break;

        case 1:     printf("MZ signature error (%d)\n", idErr);
                    break;

        case 2:     printf("PE signature error (%d)\n", idErr);
                    break;
        default:
                    break;
    }
}

void PEprinter::setFormat(uint8_t type)
{
    switch (type)
    {
        case 8:     std::cout << std::oct << std::showbase << std::left;
                    break;

        case 10:    std::cout << std::dec << std::showbase << std::left;
                    break;

        case 16:    std::cout << std::hex << std::showbase << std::left;
                    break;

        default:    break;
    }
}

void PEprinter::printSections()
{
    WORD numberOfSections = fileHead->getNumberOfSections();

    std::cout << std::endl;
    for (int i = 0; i < numberOfSections; ++i)
    {
        std::cout << secHead->getName(i) << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "VirtualAddress:\t" << secHead->getVirtualAddress(i) << std::endl;
        std::cout << "VirtualSize:\t" << secHead->getVirtualSize(i) << std::endl;
        std::cout << "SizeOfRawData:\t" << secHead->getSizeOfRawData(i) << std::endl;
        std::cout << "PointerToRawData:\t" << secHead->getPointerToRawData(i) << std::endl;
        std::cout << std::endl;
    }
}

void PEprinter::printImportTable()
{
    for (uint32_t i = 0; i < impTable->getCount(); ++i)
    {
        const char* dllName = buf + rvaToOff(impTable->getName(i));
        const char* pThunk = getPointerThunkData(i);

        while (true)
        {
            const char* pImpByName = buf + rvaToOff(READ_DWORD(pThunk));            // IMAGE_IMPORT_BY_NAME
            printf("<%s>.<%s>\n", dllName, pImpByName + sizeof(WORD));              // hint sizeof(WORD)

            pThunk = pThunk + sizeof(DWORD);
            if(!READ_DWORD(pThunk))
                break;
        }

        //std::cout << std::endl;
    }
}

void PEprinter::printAddressOfEntryPoint()
{
    std::cout << "AddressOfEntryPoint:\t" << optHead->getAddressOfEntryPoint() << std::endl;
}

void PEprinter::printImageBase()
{
    std::cout << "ImageBase:\t" << optHead->getImageBase() << std::endl;
}