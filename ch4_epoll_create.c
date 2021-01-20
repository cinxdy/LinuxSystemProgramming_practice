#include <sys.epoll.h>

// int epoll_create1 (int flags); //flags = EPOLL_CLOSEXEC

int epfd;

epfd = epoll_create1(EPOLL_CLOSEXEC);
if (epfd<0){
    perror("epoll_create1");
}
