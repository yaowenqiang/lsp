#include <malloc.h>
#include <pthread.h>

struct job {
    struc job* next;
};

struct job* job_queue;

pthread_mutext_t  job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_function(void *)
{
    while(1) {
        struct job* next_job;
        pthread_mutex_lock(&job_queue_mutex);


        if(job_queue == NULL ) {
            next_job = NULL;
        } else {
            next_job = job_queue;
            job_queue = job_queue->next;
        }

        pthread_mutex_unlock(&job_queue_mutex);

        if(next_job == NULL) {
            break;
        }
        process_job(next_job);

        free(next_job);


    }
}
