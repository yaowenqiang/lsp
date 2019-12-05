#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void print_process_environment(pid_t pid)
{
    int fd;
    char filename[24];
    char environment[8192];
    size_t length;
    char* next_var;

    snprintf(filename, sizeof(filename), "/proc/%d/environ", (int)pid);
    fd = open(filename, O_RDONLY);
    length = read(fd, environment, sizeof(length));
    environment[length] = '\0';
    close(fd);
    next_var = environment;
    while(next_var < environment + length) {
        printf("%s\n", next_var);
        next_var += strlen(next_var) + 1;
    }

}

int main(int argc, char* argv[])
{
    pid_t pid = (int)atoi(argv[1]);
    print_process_environment(pid);
    return 0;
}
    


