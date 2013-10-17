#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("hello world");

    //if a process terminates with function exit,
    //the exit function has always performed a clean shutdown of the standard I/O library
    //but function _exit/_Exit will not do that!
    //they return to kernel immediately!
    _exit(0);
}
