#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/unistd.h>

//void perror (const char *str);

int main(){
    int fd = open("./hello.txt", O_RDONLY);
    if(close(fd)==-1)
        perror("close");
    return 0;
}