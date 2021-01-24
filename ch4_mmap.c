#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// void * mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);

int main(){
    void *p;
    int len = 1;
    int fd = open("hello.txt",O_RDONLY);
    p = mmap(0, len, PROT_READ, MAP_SHARED, fd, 0);
    printf("get:%d\n",getpagesize());
    if(p==MAP_FAILED)
        perror("mmap");
    printf("%s\n",(char*)p);

}