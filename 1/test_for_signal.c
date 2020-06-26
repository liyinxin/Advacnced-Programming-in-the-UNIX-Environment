#include <stdio.h>
#include <unpv13e/apue.h>
#include <unpv13e/apueerror.h>
#include <sys/wait.h>

static void sig_int(int);//自己定义的信号处理的部分


int main(void)
{
    char   buf[MAXLINE];
    pid_t  pid;
    int    status;
    if(signal(SIGINT,sig_int) == SIG_ERR)
        err_sys("signal error");
    printf("%% ");
    while(fgets(buf,MAXLINE,stdin) != NULL){
        if(buf[strlen(buf)-1] == '\n')
            buf[strlen(buf)-1] = 0;//replace newline with NULL其实也就是'\0'
        if((pid = fork()) <0 )
            err_sys("fork error");
        else if(pid == 0){//fork被执行一次，返回两个结果；返回子进程的pid给父进程；返回pid=0给子进程
            execlp(buf,buf,(char *)0);
            err_ret("couldn't execute: %s",buf);
            exit(127);
        }
        if((pid = waitpid(pid,&status,0)) < 0){
            err_sys("waitpid error");
        }
        printf("%%");
    }
    return 0;
}

void sig_int(int signo){
    printf("interupt\n%%");
}
