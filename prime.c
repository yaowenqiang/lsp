#include <pthread.h>
#include <stdio.h>

void* compute_prime(void* args)
{
    int candicate = 2;
    int n = *((int *) args);

    while(1) {
        int factor;
        int is_prime = 1;
        for(factor = 2; factor < candicate;  ++factor) {
            if(candicate % factor  == 0) {
                is_prime = 0;
                break;
            }

            if(is_prime) {
                if(--n == 0) {
                    return (void*) candicate;
                }
            }

            ++ candicate;
        }
    }
    return NULL;

}

int main(void)
{
    pthread_t thread;
    int which_prime = 5000;
    int prime;

    pthread_create(&thread, NULL, &compute_prime, which_prime);

    pthread_join(thread, (void*) &prime);
    printf("The %dth prime number is %d\n", which_prime, prime);
    return 0;
}