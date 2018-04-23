#include <stdio.h>
#include <stdlib.h>

// setvbuf

int main(void)
{
    int i;


    printf("before while(1)");
    fflush(stdout);

    while (1);

    printf("after while(1)");
    fflush(NULL);



    exit(0);
}
