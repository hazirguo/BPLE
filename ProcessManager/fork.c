#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        printf("in the new child process!\n");
        //sleep(10);
        printf("return from child process!\n");
    }
    else if (pid > 0)
    {
        printf("in the parent process! %d return...\n", pid);
    }
    else
    {
        fprintf(stderr, "fork error! error no is %d\n", errno);
    }
    return 0;
}
