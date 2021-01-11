#include <iostream>
#include "unpv13e/apue.h"


int main()
{
    if(lseek(STDIN_FILENO,0,SEEK_CUR) == -1)
        std::cout<<"cannot seek\n";
    else
        std::cout<<"seek OK\n";
    return 0;
}

