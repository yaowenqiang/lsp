#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int spawn(char* program, char ** arg_list)
{
    pid_t child_pid;
    child_pid = fork();
    if (child_pid != 0 ) {
        return child_pid;
    }

    execvp(program, arg_list);
    fprintf(stderr, "An error occured in execvp\n");
    abort();
}
int main(void)
{
    int child_status;
    char* arg_list[] = {
        "ls",
        "-l",
        "/",
        NULL
    };
    spawn("ls", arg_list);
    wait(&child_status);

    if (WIFEXITED(child_status)) {
        printf("The child process exit normally, with exit code %d\n", child_status);
    } else {
        printf("child process exited abnormally\n");
    }

    return 0;
}
