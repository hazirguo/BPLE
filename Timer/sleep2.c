#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

static jmp_buf env_alrm;

static void sig_alrm(int signo)
{
    longjmp(env_alrm, 1);
}

unsigned int sleep2(unsigned int nsecs)
{
    if (signal(SIGALRM, sig_alrm) == SIG_ERR)
        return nsecs;
    if (setjmp(env_alrm) == 0)
    {
        alarm(nsecs);
        pause();
    }
    return alarm(0);
}

int main()
{
    printf("sleep 10 seconds....\n");
    sleep2(10);
    return 0;
}
