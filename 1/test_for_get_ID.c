#include <stdio.h>
#include <unpv13e/apue.h>
#include <unpv13e/apueerror.h>


int main()
{
    printf("hello world from process ID %ld\n",(long)getpid());
    while(1);
    return 0;
}

