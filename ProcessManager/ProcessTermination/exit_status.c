#include <stdio.h>

main()
{
    printf("hello world!\n");

    //the exit status was undefined if the main function without 
    // an explict return statement or call to the exit function
    
    //we compile this program and run it, the exit code is random
    //depending on the contents of the stack and registers contents
    //at the time that the main function returns
    //we can get the exit code using 'echo $?' after run the program
    
    //but, if we enable the 1999 ISO C compiler extensions
    //the exit code is zero if not undefined
    //we can compile using the option '-std=c99'
}
