#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>


static void f1(int,int,int,int);
static void f2(void);

static jmp_buf jmpbuffer;
static int     globval;



int main()
{
    int             autoval;
    register int    regival;
    volatile int    voltval;
    static int      statval;

    globval = 1;autoval = 2; regival = 3; voltval = 4;statval = 5;

    if(setjmp(jmpbuffer) != 0){
        printf("after longjmp:\n");
        printf("globval = %d,autoval = %d,regival = %d,voltval = %d,statval = %d\n",
               globval,autoval,regival,voltval,statval);
        exit(0);
    }

    globval = 95;autoval = 96;regival = 97;voltval = 98;statval = 99;

    f1(autoval,regival,voltval,statval);
    exit(0);
}


static void f1(int i,int j, int k,int l){
    printf("in f1(): \n");
    printf("globval = %d,autoval = %d,regival = %d,voltval = %d,statval = %d\n",
           globval,i,j,k,l);
    f2();
}

static void f2(void){
    longjmp(jmpbuffer,1);
}
