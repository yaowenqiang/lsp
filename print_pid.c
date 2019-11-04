#include <unistd.h>
#include <stdio.h>

int main(void)
{
    printf("The process ID is %d\n", getpid());
    printf("The Parent process ID is %d\n", (int)getppid());
    return 0;
}
