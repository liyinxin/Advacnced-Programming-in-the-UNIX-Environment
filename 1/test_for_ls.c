#include <stdio.h>
#include <dirent.h>//包含一些opendir的头文件
#include <unpv13e/apue.h>
#include <unpv13e/apueerror.h>

int main(int args,char *argv[])
{
    DIR           *dp;
    struct dirent *dirp;
    if(args != 2)//如果输入的参数不是2也就是运行的时候没有后边加一个目录名
        err_quit("usage: is directory_name\n");
    if((dp = opendir(argv[1])) == NULL)//注意opendir返回的结果是DIR指针,如果存在的话；如果不存在的话，那么就返回NULL
        err_sys("can't open %s",argv[1]);
    while((dirp=readdir(dp)) != NULL)
        printf("%s\n",dirp->d_name);
    closedir(dp);
    return 0;
}

