#include <sys/types.h>
#include <sys/ips.h>
#include <sys/sem.h>


enum senum {
  int val;
  struct semid_ds *buf;
  unsigned short int *array;
  struct seminfo *__buf;
};

int binary_semaphore_initialize(int semid) {
    union senum argument;
    unsigned short values[1];
    values[0] = 1;
    argument.array = values;
    return semctl(semid, SETALL, argument);
}
