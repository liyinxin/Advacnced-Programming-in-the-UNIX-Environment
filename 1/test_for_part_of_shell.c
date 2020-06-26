#include <stdio.h>
#include <unpv13e/apue.h>
#include <sys/wait.h>
#include <unpv13e/apueerror.h>

int main()
{
    char    buf[MAXLINE];
    pid_t   pid;
    int     status;

    printf("%% ");//使用%%去打印%
    while(fgets(buf,MAXLINE,stdin) != NULL){//读取一行，如果没有遇到结束符的话
        if(buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;
        if((pid = fork()) < 0){
            err_sys("fork error");
        }else if(pid == 0){
            execlp(buf,buf,(char *)0);
            err_ret("couldn't execute : %s",buf);
            exit(127);
        }
        if((pid = waitpid(pid,&status,0)) < 0)
            err_sys("waitpid error");
        printf("%%");
    }
    return 0;
}

