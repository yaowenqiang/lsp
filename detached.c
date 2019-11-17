#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_function(void* thread_arg)
{
  /* Do work here */

  printf("I'am in.\n");
  printf("Got id: %d\n", (int)pthread_self());
  sleep(50);

}

int main()
{
    pthread_attr_t attr;
    pthread_t thread;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&thread,&attr, &thread_function, NULL );
    pthread_attr_destroy(&attr);

    /* DO work here */

    /* No need to join the secodn thread */

    sleep(50);
    return 0;

}
