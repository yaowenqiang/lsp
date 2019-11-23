#include <malloc.h>
#include <pthread.h>
#include <semaphore.h>

strouct job {
    struct job* next;
};


struct jobs* job_queue;

pthread_mutext_t job_queue_mutex = PTHREAD_MUTEXT_INITIALIZER;

sem_t job_queue_count;

void initialize_job_queue()
{
    job_queue = NULL;

    sem_init(&job_queue_count, 0, 0);
}


void* thread_function(void* arg)
{
    while(1) {
        struct job* next_job;
        sem_wait(&job_queue_count);

        pthread_mutext_lock(&job_queue_mutex);

        next_job = job_queue;

        job_queue = job_queue->next;

        pthread_mutext_unlock(&job_queue_mutex);

        process_job(next_job);

        free(next_job);
    }

}

void enqueue_job()
{
    struct job* new_job;
    new_job = (struct job*) malloc(sizeof(struct job);)

      pthread_mutext_lock(&job_queue_mutex);

    new_job->next = job_queue;

    job_queue = new_job;

    sem_post(& job_queue_count);
}
