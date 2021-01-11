#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <grp.h>
#include <time.h>



int main(void){
    time_t a;
    struct passwd *ptr = getpwnam("zailushang");
    printf("zailushang's username is %s\n",ptr->pw_name);
    printf("zailushang's user id is %d\n",ptr->pw_uid);
    printf("zailushang's user shell is %s\n",ptr->pw_shell);
    
    time_t t;//time_t -----> long int
    struct tm *tmp;
    char buf1[16];
    char buf2[64];

    time(&t);
    tmp = localtime(&t);
   

    if(strftime(buf1,16,"time and date: %r,%a %b %d, %Y",tmp) == 0)
        printf("buffer length 16 is too small\n");
    else
        printf("%s\n",buf1);
    if(strftime(buf2,64,"time and date: %r,%a %b %d, %Y",tmp) == 0)
        printf("buffer length 16 is too small");
    else
        printf("%s\n",buf2);
    return 0;
}