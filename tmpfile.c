#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#define BSIZE 10

int main(void)
{
    
    //FILE * tmp = tmpfile();
    FILE * tmp = fopen("tmp.txt", "r+");
    int read_count, write_count, i;

    //char * output = malloc(sizeof(char));
    char input[BSIZE] ;

    for(i=0;i<BSIZE;i++) {
        input[i] = 'a';
    }
    char output[BSIZE];
    for(i=0;i<BSIZE;i++) {
        output[i] = 'b';
    }
   write_count = fwrite(input, 3, 2 , tmp) ;
   printf("write %d characters.\n", write_count);

    //fclose(tmp);

    tmp = fopen("tmp1.txt", "r+");
    assert(tmp != NULL);
    if (tmp == NULL ) {
        perror(strerror(errno));
        fprintf(stderr, "error reading tmp file %s\n: ", strerror(errno));
        exit(EXIT_FAILURE);
    }
    //tmp = tmpfile();
    fflush(tmp);
    read_count = fread(output,1, 1, tmp);
    printf("read %d characters.\n", read_count);
    fclose(tmp);
    return 0;
}
