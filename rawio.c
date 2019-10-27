#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *buffer;
    int fd, size, count, i, j;
    if (argc != 3) {
        printf("usage: %s blocksie blockcount\n", argv[0]);
        exit(1);
    }

    fd = open("rawio.out", O_WRONLY | O_CREAT | O_TRUNC, 0600);
    size = atoi(argv[1]);
    count = atoi(argv[2]);
    
    buffer = malloc(size);
    for (j = 0; j < size; j++) {
        buffer[j] = '0';
    }

    for (i = 0; i < count; i++) {
       write(fd, buffer ,size); 
    }

    close(fd);
    return 0;
}

//./time rawio 1 10000000

