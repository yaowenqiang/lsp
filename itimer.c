#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

void timer_handler(int signum) 
{
    static int count = 0;
    printf("timer expired %d times\n", ++count);
}

int main()
{
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timer_handler;

    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 250000;

    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 250000;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);
    while(1);


}
