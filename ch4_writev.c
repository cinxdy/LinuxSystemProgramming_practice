#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>

// ssize_t readv (int fd, const, struct iovec *iov, int count);
// ssize_t writev (int fd, const, struct iovec *iov, int count);
/* struct iovec { 
    void *iov_base;
    size_t iov_len;   
} */

int main(){
    struct iovec iov[3];
    ssize_t nr;
    int fd, i;

    char *buf[] ={
        "Why not change the world?\n",
        "Hello World!\n",
        "MCNL"
    };

    fd = open("hello.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if (fd == -1){
        perror("open");
        return 1;
    }   

    for(i=0;i<3;i++){
        iov[i].iov_base = buf[i];
        iov[i].iov_len = strlen(buf[i])+1;
    }

    nr = writev(fd, iov, 3);
    if (nr==-1){
        perror("writev");
        return 1;
    }
    printf("wrote %d bytes\n",nr);

    if (close(fd)){
        perror("close");
        return 1;
    }
    return 0;
}
