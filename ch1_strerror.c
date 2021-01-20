#include <string.h>
#include <errno.h>
#include <stdio.h>

// char * strerror (int errnum);
// char * strerror_r (int errnum, char *buf, size_t len);

int main(){
    char str[100];
    int result;

    printf("%s\n", strerror(E2BIG));
    
    result = strerror_r(E2BIG, str, 99);
    printf("%d\n", result);
    
    return 0;
}