#include <sys/epoll.h>
#include <stdio.h>
#define MAX_EVENTS 64

// int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);

int main(){
    struct epoll_event *events;
    int nr_events, i, epfd;

    epfd = epoll_create1(EPOLL_CLOSEXEC);
    if (epfd<0){
        perror("epoll_create1");

    //wait event
    events = malloc(sizeof(struct epoll_event)* MAX_EVENTS);
    if(!events){
        perror("malloc");
        return 1;
    }    

    nr_events = epoll_wait(epfd, events, MAX_EVENTS, -1); // timeout == -1 nonstop
    if(nr_events<0){
        perror("epoll_wait");
        free(events);
        return 1;
    }

    for(i=0;i<nr_events;i++){
        printf("event=%ld on fd=%d\n", evets[i].events, events[i].data.fd);
    }

}
