#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>

sig_atomic_t sigusr1_count = 0;

void handler(int signal_number) {
    ++sigusr1_count;
}

int main(void)
{
    struct sigaction sa;
    memset (&sa, 0, sizeof(sa));
    sa.sa_handler = &handler;
    printf("%d\n", getpid());

    sigaction(SIGUSR1, &sa, NULL);
    sleep(1000);

    printf("SIGUSR1 was raised %d time\n", sigusr1_count);
    return 0;
}
