#include <stdio.h>
#include <unistd.h>
#include <error.h>

int     globvar = 6;
char    buf[] = "a write to stdout\n";


int main(void)
{
    int     var;
    pid_t   pid;

    var = 88;
    if(write(STDOUT_FILENO,buf,sizeof(buf)-1) != sizeof(buf)-1)
        perror("write error");

    printf("before fork\n");
    
    if((pid = fork()) < 0){
        perror("fork error");
    }else if(pid == 0){//子进程的返回值
        globvar++;
        var++;
    }else{//父进程的返回
        sleep(2);
    }

    printf("pid = %ld,glob = %d,var = %d\n",(long)getpid(),globvar,var);
    return 0;
}

