#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(void)
{
    struct stat sb;
    stat("foo", &sb);

    printf("Last accessed: %s", ctime(&sb.st_atime));
    printf("Last modified: %s", ctime(&sb.st_mtime));
    printf("Last change:   %s", ctime(&sb.st_ctime));
    return 0;
}
