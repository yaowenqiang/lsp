#include <fcntl.h>

int main()
{
    int fd;
    fd = open("foo", O_WRONLY | O_CREAT, 8644);
    write(fd, "Hello world", 11);
    close(fd);

}
