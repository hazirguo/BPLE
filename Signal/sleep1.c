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
    sleep(11);
    pause();          //sleep, the SIGALRM wakes up 
    return alarm(0);  //turn off timer, return unslept time
}


int main()
{
    printf("sleep for 100 seconds....\n");
    unsigned int unslept_time = 10;
    while (unslept_time != 0)
    {
        unslept_time = sleep1(unslept_time);
        printf("unslept time is %u\n", unslept_time);
    }
    return 0;
}

