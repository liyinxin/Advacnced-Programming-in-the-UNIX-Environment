#include <stdio.h>      //printf函数需要
#include <unistd.h>
int sum(int a)
{
    auto b = 0;
    static int c = 3;
    b++;
    c += 3;
    return a+b+c;
}
int main(void)
{
    int a = 2;
    write(STDOUT_FILENO,"hello",6);
    for(int i=0;i<3;i++)
        printf("%d\n",sum(a));
    while(1);
    return 0;
}
