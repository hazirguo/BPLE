#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void timerfunc(int signo)
{
    printf("alarm....\n");
}

int main()
{
    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 500000;

    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    signal(SIGALRM, timerfunc);

    setitimer(ITIMER_REAL, &timer, NULL);
    pause();

    return 0;
}
