#include <stdlib.h>
#include <stdio.h>

static void my_exit1(void);
static void my_exit2(void);

int main()
{
    if (atexit(my_exit2) != 0)
        fprintf(stderr, "cannot register my_exit2\n");
    
    if (atexit(my_exit1) != 0)
        fprintf(stderr, "cannot register my_exit1\n");

    if (atexit(my_exit1) != 0)
        fprintf(stderr, "cannot register my_exit1\n");

    printf("main is done!\n");

    //return 0 equals to exit(0)
    //exit calls threse function in reverse order of their registeration
    return 0;
}

static void my_exit1(void)
{
    printf("first exit handler\n");
}

static void my_exit2(void)
{
    printf("second exit handler\n");
}
