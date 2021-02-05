#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>



void pr_exit(int status){
    /*
        WIFEXITED(status)     全称是wait if exited
        WEXITSTATUS(status)   全称是wait exit status
    如果WIFEXITED(status)为真，则使用WEIXTSTATUS(status)以获取进程退出
的状态
    */
    if(WIFEXITED(status))
        printf("normal termination,exit status = %d\n",WEXITSTATUS(status));
    /*
     *  WIFSIGNALED(status)   全称是wait if signaled
     *  WTERMSIG(status)      全称是wait term signal
    如果WIFSIGNALED(status)为真，则使用宏WTERMSIG(status)以获得使进程终
止的那个信号的编号。注意，有些实现定义宏WCOREDUMP(status)，若已产生终止
进程的core文件，则它返回真。
     */
    else if(WIFSIGNALED(status))
        printf("abnormal termination,signal number = %d%s\n",
               WTERMSIG(status),
#ifdef WCOREDUMP
               WCOREDUMP(status) ? " (core file generated)" : "");
#else
              "");
#endif
    else if(WIFSTOPPED(status))
        printf("child stopped,signal number = %d\n",
               WSTOPSIG(status));

}

int main()
{
    pid_t   pid;
    int     status;
    /*
     *  fork()  产生一个进程，返回值有两个：
     *      子进程返回的值是0，
     *      父进程返回的值是子进程的ID。
     *  pid_t wait(int *status);返回的是终止进程的ID，
     *      然后status里返回的是其终止的状态值是多少。                    
     */

    if((pid=fork()) < 0)
        perror("fork error");
    else if(pid == 0)//子进程
        exit(7);
    if(wait(&status) != pid)//等待子进程的结束
        perror("wait error");
    pr_exit(status);

    
    if((pid=fork()) < 0)
        perror("fork error");
    else if(pid == 0)//子进程
        abort();
    if(wait(&status) != pid)
        perror("wait error");
    pr_exit(status);
    

    if((pid=fork()) < 0)
        perror("fork error");
    else if(pid == 0){
        status /= 0;
    }
    if(wait(&status) != pid)
        perror("wait error");
    pr_exit(status);

    return 0;
}

