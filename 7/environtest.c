#include <stdio.h>
#include <unistd.h>

int main()
{
    extern char **environ;
    printf("Hello world\n");
    for(int i = 0; environ[i] != NULL;++i)
        printf("envrion[%d]: %s\n",i,environ[i]);
    return 0;
}

