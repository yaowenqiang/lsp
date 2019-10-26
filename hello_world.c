#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd;
    /* 
    fd = open("foo", O_WRONLY | O_CREAT, 8644);
    if (fd < 0) {
        printf("Error number %d\n", errno);
        perror("foo");
        exit(1);
    } */
    if ((fd = open("foo", O_WRONLY | O_CREAT, 0644)) < 0) {
        printf("Error number %d\n", errno);
        perror("foo");
        exit(1);
    }
    write(fd, "Hello world", 11);
    close(fd);

}
