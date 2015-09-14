#ifndef DATAREADER
#define DATAREADER

#include <stdint.h>

typedef uint32_t DWORD;
typedef uint16_t WORD;
typedef uint8_t BYTE;

#define READ_BYTE(p) (((unsigned char*)(p))[0])
#define READ_WORD(p) ((((unsigned char*)(p))[0]) | ((((unsigned char*)(p))[1]) << 8))
#define READ_DWORD(p) ((((unsigned char*)(p))[0]) | ((((unsigned char*)(p))[1]) << 8) | \
    ((((unsigned char*)(p))[2]) << 16) | ((((unsigned char*)(p))[3]) << 24))

#define ALIGN_DOWN(x, align)  (x & ~(align-1))
#define ALIGN_UP(x, align)    ((x & (align-1))?ALIGN_DOWN(x,align)+align:x)

#endif // DATAREADER
