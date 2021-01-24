#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <error.h>

// pid_t fork(void);

int main(){
    pid_t pid;
     
    pid = fork();
    if(pid>0)
        printf("I am the parent of pid=%d\n",pid);
    else if(!pid)
        printf("I am the child!\n");
    else if(pid==-1)
        perror("fork");
    
    return 0;
}