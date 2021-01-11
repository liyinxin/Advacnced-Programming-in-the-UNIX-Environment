#include <stdio.h>

int main(int argc,char *argv[])
{
    //因为ISO C跟 POSIX.1都要求argv[argc]是一个空指针
    for(int i = 0; argv[i] != NULL;++i)
        printf("argv[%d]: %s\n",i,argv[i]);
    return 0;
}

