#include <stdio.h>
#include <unpv13e/apue.h>
#include <unpv13e/apueerror.h>

int main()
{
    printf("uid = %d, gid = %d\n",getuid(),getgid());
    return 0;
}

