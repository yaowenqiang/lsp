#include <errno.h>
#include <time.h>

int better_sleep(double sleep_time)
{
    struct timespec tv;
    tv.tv_sec = (time_t)sleep_time;
    tv.tv_nsec = (long) ((sleep_time - tv.tv_sec) * 1e+9);
    while(1) {
        int rval = nanosleep(&tv, &tv);
        if (rval == 0 ) {
            return 0;
        } else if (errno == EINTR) {
            continue;
        } else {
            return rval;
        }
    }
    return 0;
}

int main(void) 
{
  better_sleep(10);
  return 0;
}
