#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



int main()
{
    pid_t pid;

    if((pid = fork()) < 0)
        perror("fork error");
    else if(pid == 0){//子进程处理
        if((pid = fork()) < 0)
            perror("fork error");
        else if(pid > 0)//子进程本身，自己终止了
            exit(0);
        //现在这个进程是子进程的子进程
        sleep(2);//这个时候，其变成了僵死进程
        printf("second child,parent pid = %ld\n",(long)getppid());
        exit(0);
    }

    if(waitpid(pid,NULL,0) != pid)
        perror("waitpid error");
    exit(0);
}

