#include <stdint.h>
#include <stdio.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[]) 
{
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");

    BYTE b;

    while (fread(&b, 1, 1, src) != 0) {
        fwrite(&b, 1, 1, dst);
    }

    fclose(dst);
    fclose(src);
}