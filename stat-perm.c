#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    const char * const filename = argv[1];
    struct stat buf;
    stat(filename, &buf);
    if(buf.st_mode & S_IWUSR) {
        printf("Owner user chan write '%s'\n", filename);
    }
    return 0;
}
