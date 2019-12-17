#include <errno.h>
#include <stdio.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
    char target_path[255];
    char* link_path = argv[1];
    int len = readlink(link_path, target_path, sizeof(target_path));
    if (len == -1) {
        if (errno == EINVAL) {
            fprintf(stderr, "%s is not a symbolic link\n", link_path);
        } else {
            perror("readlink");
        }
    } else {
        target_path[len] = '\0';
        printf("%s\n", target_path);
    }
    return 1;
}
