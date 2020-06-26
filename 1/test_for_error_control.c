#include <stdio.h>
#include <error.h>
#include <unpv13e/apue.h>
#include <unpv13e/apueerror.h>


int main(int argc,char *argv[])
{
    fprintf(stderr,"EACCES: %s\n",strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    return 0;
}

