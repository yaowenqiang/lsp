#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    
    pid_t child_pid;
    printf("The main process ID is %d\n", getpid());
    child_pid = fork();
    if (child_pid != 0) {

        printf("This is the Parnet process with process id = %d\n", (int)getpid());
        printf("The Child process id  is %d\n", child_pid);
    } else {
        printf("This is the Child process with process id = %d\n", (int)getpid());
    }
    return 0;
}
