#include <sys/epoll.h>

// int epoll_ctl (int epfd, int op, int fd, struct epoll_event *event);

// struct epoll_event{
//     __u32 events;
//     union{
//         void *ptr;
//         int fd;
//         __u32 u32;
//         __u64 u64;
//     } data;
// };

int main(){
    struct epoll_event event;
    int ret;
    int fd = 1;

    event.data.fd = fd; // why fd? epoll_wait에서 반환?
    event.events = EPOLLIN | EPOLLOUT;

    ret = epoll_ctl (epfd, EPOLL_CTL_ADD, fd, &event);
    if(ret)
        perror("epoll_ctl");

}