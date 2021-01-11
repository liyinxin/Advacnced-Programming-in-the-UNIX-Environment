#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>


using namespace std;
#define BUFFERSIZE 4096


int main()
{
    int n;
    char buf[BUFFERSIZE];
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int fd = open("test",O_RDWR | O_CREAT | O_TRUNC,mode);
    int rd = open("hello",O_RDONLY);
    while( (n=read(rd,buf,BUFFERSIZE)) >0){//注意逻辑运算符的优先级是大于赋值运算符的，所以要加括号
        cout<<buf<<endl;
        cout<<"the n is "<<n<<endl;
        if(write(fd,buf,n) != n)
            perror("write error\n");
    }
    if(n < 0)
        perror("read error\n");
    return 0;
}
