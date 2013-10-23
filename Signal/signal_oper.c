#include <stdio.h>
#include <signal.h>

static void sig_quit(int signo);

int main(void)
{
    sigset_t    newmask, oldmask, pendmask;

    if (signal(SIGQUIT, sig_quit) == SIG_ERR)
        printf("cannot catch SIGQUIT!\n");

    /* block SIGQUIT
     * save the current signal set to oldmask
     */
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);
    sigprocmask(SIG_BLOCK, &newmask, &oldmask);

    sleep(10);    // if you send SIGQUIT, the process will not terminate

    sigpending(&pendmask);

    if (sigismember(&pendmask, SIGQUIT))
        printf("SIGQUIT pending!\n");

    /* reset the old signal mask */
    sigprocmask(SIG_SETMASK, &oldmask, NULL);

    printf("SIGQUIT unblocked!\n");

    sleep(10);   //if you send SIGQUIT, the process will terminate & coredump

    exit(0);
}

static void sig_quit(int signo)
{
    printf("caught SIGQUIT!\n");
    signal(SIGQUIT, SIG_DFL);
}
