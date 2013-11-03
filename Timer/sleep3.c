#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sig_alarm(int signo)
{
    // do nothing
}

unsigned int sleep3(unsigned int nsecs)
{
    struct sigaction  newact, oldact;
    sigset_t  newmask, oldmask, suspendmask;

    unsigned int unslept;
    
    //set our handler, save previous information
    newact.sa_handler = sig_alarm;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);
    sigaction(SIGALRM, &newact, &oldact);

    //block SIGALRM and save current signal mask
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGALRM);
    sigprocmask(SIG_BLOCK, &newmask, &oldmask);

    alarm(nsecs);

    suspendmask = oldmask;
    sigdelset(&suspendmask, SIGALRM);
    sigsuspend(&suspendmask);

    //some signal has been caught, SIGALRM is now blocked

    unslept = alarm(0);

    //reset previous action
    sigaction(SIGALRM, &oldact, NULL);

    //reset signal mask, which unblocks SIGALRM
    sigprocmask(SIG_SETMASK, &oldmask, NULL);
    return unslept;
}

int main()
{
    printf("sleep 10 seconds...\n");
    sleep3(10);
    return 0;
}
