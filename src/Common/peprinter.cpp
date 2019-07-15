#include "Common/peprinter.h"

void PEprinter::PrintError()
{
    int idErr = GetState();

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

void PEprinter::SetFormat(uint8_t type)
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

void PEprinter::PrintSections()
{
    WORD numberOfSections = _fileHead->GetNumberOfSections();

    std::cout << std::endl;
    for (int i = 0; i < numberOfSections; ++i)
    {
        std::cout << _secHead->GetName(i) << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "VirtualAddress:\t" << _secHead->GetVirtualAddress(i) << std::endl;
        std::cout << "VirtualSize:\t" << _secHead->GetVirtualSize(i) << std::endl;
        std::cout << "SizeOfRawData:\t" << _secHead->GetSizeOfRawData(i) << std::endl;
        std::cout << "PointerToRawData:\t" << _secHead->GetPointerToRawData(i) << std::endl;
        std::cout << std::endl;
    }
}

void PEprinter::PrintImportTable()
{
    for (uint32_t i = 0; i < _impTable->GetCount(); ++i)
    {
        const char* dllName = _buf + RvaToOff(_impTable->GetName(i));
        const char* pThunk = GetPointerThunkData(i);

        while (true)
        {
            const char* pImpByName = _buf + RvaToOff(READ_DWORD(pThunk));            // IMAGE_IMPORT_BY_NAME
            printf("<%s>.<%s>\n", dllName, pImpByName + sizeof(WORD));              // hint sizeof(WORD)

            pThunk = pThunk + sizeof(DWORD);
            if(!READ_DWORD(pThunk))
                break;
        }

        //std::cout << std::endl;
    }
}

void PEprinter::PrintAddressOfEntryPoint()
{
    std::cout << "AddressOfEntryPoint:\t" << _optHead->GetAddressOfEntryPoint() << std::endl;
}

void PEprinter::PrintImageBase()
{
    std::cout << "ImageBase:\t" << _optHead->GetImageBase() << std::endl;
}
