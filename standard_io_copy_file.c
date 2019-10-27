/*
 * Trivial file copy program using standard I/O library
 */

#include <stdio.h>

#define BSIZE 16384

int main(void)
{
    FILE *fin, *fout;
    char buf[BSIZE];
    int count;
    fin = fopen("foo", "r");
    fout = fopen("bar", "w");
    while((count = fread(buf, 1, BSIZE, fin)) > 0) {
        fwrite(buf, 1, count, fout);
    }

    return 0;
}   
