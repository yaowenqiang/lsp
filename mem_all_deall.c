#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

union senum {
  int val;
  struct semid_ds *buf;
  unsigned short int *array;
  struct seminfo *__buf;
};

int binary_semphore_allocation(key_t key, int sem_flags)  {
    return semget(key, 1, sem_flags);
}


int binary_semphore_deallocate(int semid)
{
    union semnu ignored_argument;
    return semctl(semid, 1, IPC_RMID, ignored_argument);
}


