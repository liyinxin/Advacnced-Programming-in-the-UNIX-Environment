#include <stdio.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

void make_temp(char *temp);
int main(void)
{
    char good_temp[] = "/tmp/dirXXXXXX";/*right way*/
    char *bad_temp   = good_temp;/*bad   way*/

    printf("trying to create first temp file...\n");
    make_temp(good_temp);
    printf("trying to create second temp file...\n");
    make_temp(bad_temp);
    return 0;
}


void make_temp(char *temp){
    int fd;
    struct stat sbuf;
    printf("传入的参数是%s \n",temp);
    if((fd = mkstemp(temp)) < 0)
        perror("can't create temp file");
    printf("temp name = %s\n",temp);
    close(fd);
    if(stat(temp,&sbuf) < 0){
        if(errno == ENOENT)
            printf("file doesn't exist\n");
        else
            perror("stat failed");
    }else{
        printf("file exists\n");
        unlink(temp);
    }
}
