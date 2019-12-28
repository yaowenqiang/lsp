#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int  secure_temp_file()
{
    static int random_fd = -1;
    unsigned int random;
    char filename[128];

    int fd;
    struct stat stat_buf;

    if (random_fd == -1) {
        random_fd = open("/dev/random", O_RDONLY);
        if (random_fd == -1) {
            return -1;
        }
    }


    if(read(random_fd, &random, sizeof(random)) !=  sizeof(random)) {
        return -1;
    }

    sprintf(filename, "/tmp/%u", random);


    fd = open(filename, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
    //man 2 open

    if (fd == -1) {
        return -1;
    }

    if(lstat(filename, &stat_buf) == -1) {
        return -1;
    }
    if(!S_ISREG(stat_buf.st_mode)) {
        return -1;
    }

    if (stat_buf.st_uid != geteuid() || stat_buf.st_gid != getegid()) {
        return -1;
    }

    if((stat_buf.st_mode & ~ (S_IRUSR | S_IWUSR)) != 0) {
        return -1;
    }

    return fd;
}

int main() {
  secure_temp_file();
  return 0;
}
