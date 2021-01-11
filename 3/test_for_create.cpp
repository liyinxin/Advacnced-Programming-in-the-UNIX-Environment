#include <iostream>
#include "unpv13e/apue.h"
#include "unpv13e/apueerror.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
char buf3[10];


int main()
{
    int fd;//用来保存文件描述符

    if((fd = creat("file.hole",FILE_MODE)) < 0)//FILE_MODE 这里定义成默认普通用户，具有读写权限
        //组用户和其他用户只有读权限
        err_sys("create error");
    
    if(write(fd,buf1,10) != 10)
        err_sys("buf1 write error");

    if(lseek(fd,16384,SEEK_SET) == -1)
        err_sys("lseek error");

    if(write(fd,buf2,10) != 10)
        err_sys("buf2 write error");

    //read之前，必须先得打开一个文件获得相应的文件描述符才可以
    fd = open("file.hole",O_RDONLY);
    if(read(fd,buf3,10) == -1)
        err_sys("read error");
    std::cout<<"read from the file.hole is "<<buf3<<std::endl;
    return 0;
}

