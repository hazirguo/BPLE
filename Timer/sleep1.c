#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void sig_alrm(int signo)
{
    //printf("alarm!\n");
    /* nothing to do, just return to wake up the pause */
}

unsigned int sleep1(unsigned int nsecs)
{
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        return nsecs;

    alarm(nsecs);     //start the timer
    pause();          //sleep, the SIGALRM wakes up 
    return alarm(0);  //turn off timer, return unslept time
}


int main()
{
    printf("sleep for 10 seconds....\n");
    unsigned int unslept_time = 10;
    unslept_time = sleep1(unslept_time);
    return 0;
}

