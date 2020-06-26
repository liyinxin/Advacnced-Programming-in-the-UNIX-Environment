#include <stdio.h>
#include <unpv13e/apue.h>
#include <unpv13e/apueerror.h>

#define BUFFSIZE 4096
int main()
{
    int  n;
    char buf[BUFSIZ];
    write(1,"hello",6);
    printf("the STDIN_FILENO is %d",STDIN_FILENO);
    while((n = read(STDIN_FILENO,buf,BUFSIZ)) > 0){
        printf("the STDIN_FILENO is %d",STDOUT_FILENO);
        if(write(STDOUT_FILENO,buf,n) != n)
            err_sys("write error");
    }
       if(n < 0)
        err_sys("read error");
    return 0;
}

