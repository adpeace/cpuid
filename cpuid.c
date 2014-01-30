#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include <errno.h>

void u32_to_bin(uint32_t in, char s[])
{
    int i;
    for (i = 1; i <= 32; i++)
    {
        s[32-i] = in & (1 << (i-1)) ? '1' : '0';
    }
}

int main(int argc, char* argv[])
{
    uint32_t eax, ebx, ecx, edx;
    char eax_s[33], ebx_s[33], ecx_s[33], edx_s[33];

    memset((void *)eax_s, 0, sizeof(eax_s));
    memset((void *)ebx_s, 0, sizeof(ebx_s));
    memset((void *)ecx_s, 0, sizeof(ecx_s));
    memset((void *)edx_s, 0, sizeof(edx_s));

    if (argc != 2)
    {
        printf("Usage: cpuid <eax>\n");
        return 2;
    }

    eax = (long) strtoul(argv[1], NULL, 0);
    printf("Input: eax = %u\n", eax);

    asm volatile ( "cpuid"
         : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx)
         : "a" (eax)
         );

    u32_to_bin(eax, eax_s);
    u32_to_bin(ebx, ebx_s);
    u32_to_bin(ecx, ecx_s);
    u32_to_bin(edx, edx_s);
    printf("eax = %s %u\n"
           "ebx = %s %u\n"
           "ecx = %s %u\n"
           "edx = %s %u\n", eax_s, eax, ebx_s, ebx, ecx_s, ecx, edx_s, edx);

    printf("%.4s%.4s%.4s\n", (char*)&ebx, (char*)&edx, (char*)&ecx);
    return 0;
}

