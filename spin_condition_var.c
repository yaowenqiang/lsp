#include <pthread.h>

int thread_flag;

pthread_mutex_t thread_flag_mutex;

void initialize_flag()
{
    pthread_mutex_init(&thread_flag_mutex, NULL);

    thread_flag = 0;
}

void thread_function(void* thread_arg)
{
    while(1)
    {
        int flag_is_set;
        pthread_mutex_lock(&thread_flag_mutex);
        flag_is_set = thread_flag;

        pthread_mutex_unlock(&thread_flag_mutex);


        if(flag_is_set) {
            do_work();
        }
    }
}

void set_thread_flag(int flag_value)
{
    pthread_mutex_lock(&thread_flag_mutex);

    thread_flag = flag_value;

    pthread_mutex_unlock(&thread_flag_mutex);
}
