#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
    pid_t pid = getpid();
    printf("My pid is %d\n", pid);

    abort();
    //loop forever here
    while(1)
    {}

    return 0;
}
