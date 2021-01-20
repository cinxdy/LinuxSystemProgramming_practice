#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

// 전체 범위가 유효한 반환값인 경우 error handling
// unsigned long int strtoul(const char *nptr, char **endptr, int base);

int main(){
    int arg;
    char buf[100];

    errno = 0;
    arg = strtoul (buf, NULL, 0);
    if(errno)
        perror("strtoul");

    return 0;
}