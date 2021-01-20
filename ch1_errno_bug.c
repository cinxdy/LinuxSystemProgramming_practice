#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//int fsync(int fd);

int main(){
    int fd =3;
    if(fsync (fd) == -1){
        fprintf (stderr, "fsync failed!\n");
        if (errno == EIO)
            fprintf (stderr, "I/O error on %d!\n", fd);
    }

    
    if (fsync (fd) == -1){
        const int err = errno;
        fprintf (stderr, "fsync failed: %s\n", strerror(errno));
        if(err == EIO)
            fprintf (stderr, "I/O error on %d!\n", fd);
    }

    return 0;
}