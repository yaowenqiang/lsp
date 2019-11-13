#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

sig_atomic_t child_exit_status;

void clean_up_child_process(int signal_number)
{
    int status;
    wait(&status);
    child_exit_status = status;

}


int main(void)
{

    struct sigaction sigchild_action;
    memset(&sigchild_action, 0, sizeof(sigchild_action));
    sigchild_action.sa_handler = &clean_up_child_process;
    sigaction(SIGCHLD, &sigchild_action, NULL);

    return 0;
}
