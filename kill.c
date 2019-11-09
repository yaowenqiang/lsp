#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

int main(void) {
    pid_t pid;
    scanf("%d", &pid);
    kill(pid, SIGTERM);
    return 0;
}