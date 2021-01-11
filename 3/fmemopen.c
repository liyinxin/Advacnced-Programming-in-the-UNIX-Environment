#include <stdio.h>
#include <sys/errno.h>
#include <sys/unistd.h>
#include <string.h>
#include <pwd.h>

#define BSZ 48

int main()
{
    FILE *fp;
    char buf[BSZ];
    char newBuffer[130];

 
    memset(buf,'a',BSZ-2);
    buf[BSZ-2]='\0';
    buf[BSZ-1]='X';
    printf("最开始的时候,buf是: %s\n",buf);
    if((fp = fmemopen(buf,BSZ,"w+")) == NULL)
        perror("fmemopen failed");                         
    //setbuf(fp,NULL);
    printf("目前位置指示器在: %d\n",ftell(fp));
    printf("被fmemopen打开以后我的buf的内容: %s\n",buf);
    //此时的buf并没有被截断!!!!，仅仅是在第一个位置放置了null字符
    for(int i = 0; i < BSZ-2;++i){
        if(buf[i] == '\0')
            printf("0");
        else
            printf("%c",buf[i]);
    }
    printf("\n");
    fprintf(fp,"hello, world");
    //buf:\0hello, world
    printf("目前位置指示器在: %d\n",ftell(fp));
    printf("没有被冲洗的时候:\n");
    for(int i = 0; i < BSZ-2;++i){
        if(buf[i] == '\0')
            printf("0");
        else
            printf("%c",buf[i]);
    }
    fflush(fp);
    printf("\nafter fflush: \n");
    printf("目前位置指示器在: %d\n",ftell(fp));
    for(int i = 0; i < BSZ-2;++i){
        if(buf[i] == '\0')
            printf("0");
        else
            printf("%c",buf[i]);
    }
    printf("\nnow buf is: \n");
    for(int i = 0; i < BSZ-2;++i){
        if(buf[0] == '\0')
            printf("\nhello\n");
        else
            printf("%c",buf[i]);
    }
    printf("\nlen of string in buf = %ld\n",(long)strlen(buf));


    memset(buf,'b',BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';
    printf("目前位置指示器在: %d\n",ftell(fp));
    fprintf(fp,"hello, world");
    fseek(fp,0,SEEK_SET);//fseek会引发flush这个操作
    for(int i = 0; i < BSZ-2;++i){
        if(buf[i] == '\0')
            printf("0");
        else
            printf("%c",buf[i]);
    }
    printf("\nlen of string in buf = %ld\n",(long)strlen(buf));

    memset(buf,'c',BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';
    fprintf(fp,"hello, world");
    fclose(fp);
    printf("after fclose: %s\n",buf);
    printf("len of string in buf = %ld\n",(long)strlen(buf));

    return 0;
}

