#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



static void my_exit1(void);
static void my_exit2(void);


int main(int argc,char *argv[]){
    if(atexit(my_exit2) != 0)
        perror("can't register my_exit2");
    if(atexit(my_exit1) != 0)
        perror("can't register my_exit1");

    if(atexit(my_exit1) != 0)
        perror("can't register my_exit1");

    printf("main is done\n");

    return 2;
}

static void my_exit1(void){
    printf("first exit handler\n");
}

static void my_exit2(void){
    printf("second exit handler\n");
}
