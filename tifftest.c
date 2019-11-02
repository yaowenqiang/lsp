#include <stdio.h>
#include <tiffio.h>

int main(int argc, char *argv[])
{
    TIFF* tiff;
    tiff = TIFFOpen(argv[1], "r");
    TIFFClose(tiff);
    return 0;
}

//gcc -o tifftest tifftest.c -ltiff
// ldd ./tifftest
// gcc -static -o tifftest2  tifftest.c   -ltiff -llzma  -ljpeg -lz -lm -ldl -ljbig.so.0
