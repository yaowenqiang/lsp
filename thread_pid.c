#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* thread_function (void* thread_arg)
{
    fprintf(stdout, "child thread pid is %d\n", (int)getpid());
    while(1);

}

int main() 
{
    pthread_t thread;
    fprintf(stdout, "main thread pid is %d\n", (int)getpid());
    pthread_create(&thread, NULL, &thread_function, NULL);
    while(1);
}
