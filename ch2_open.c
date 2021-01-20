#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

//int open (const char *name, int flags);
//int open (const char *name, int flags, mode_t mode);

int main(){
    int fd;
    //fd = open("./hello.txt", O_WRONLY | O_CREAT);
    fd = open("./hello.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO); // 권한 777
    if (fd == -1)
        perror("error");

    return 0;
}