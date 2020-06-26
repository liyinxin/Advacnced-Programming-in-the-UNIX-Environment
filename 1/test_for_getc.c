#include <stdio.h>
#include <unpv13e/apue.h>
#include <unpv13e/apueerror.h>


int main()
{
    int     c;
    while((c = getc(stdin)) != EOF)
        if(putc(c,stdout) == EOF)
            err_sys("output error");
    if(ferror(stdin))
        err_sys("input error");
    return 0;
}

