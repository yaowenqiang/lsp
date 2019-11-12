#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  pid_t child_pid;
  child_pid = fork();
  if(child_pid > 0 ) {
      //this is the parent process, Sleep for a minutes
      sleep(60);
  } else {
      //This is the child process, exit immediately
      exit(0);
  }

  return 0;
}
