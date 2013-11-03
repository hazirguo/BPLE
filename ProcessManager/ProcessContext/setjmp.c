#include <setjmp.h>
#include <stdio.h>

static jmp_buf env;

int main()
{
    if (setjmp(env) == 0)
    {
        printf("hello world!\n");
        longjmp(env, 1);
    }
    else
    {
        printf("hello world 2!\n");
    }

    return 0;
}
