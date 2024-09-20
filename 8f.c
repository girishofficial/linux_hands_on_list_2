/*
============================================================================
Name : 8f.c
Author : GIRISH KUMAR SAHU
Description : Catch SIGVTALRM (setitimer system call)
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void handle_sigvtalrm(int signum) {
    printf("Caught SIGVTALRM\n");
}

int main() {
    signal(SIGVTALRM, handle_sigvtalrm);
    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_VIRTUAL, &timer, NULL);
    while (1);
    return 0;
}

/*
Output:
Caught SIGVTALRM
Caught SIGVTALRM
Caught SIGVTALRM
...
*/

