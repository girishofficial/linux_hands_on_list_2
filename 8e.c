/*
============================================================================
Name : 8e.c
Author : GIRISH KUMAR SAHU
Description : Catch SIGALRM (setitimer system call)
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void handle_sigalrm(int signum) {
    printf("Caught SIGALRM\n");
}

int main() {
    signal(SIGALRM, handle_sigalrm);
    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
    while (1);
    return 0;
}

/*
Output:
Caught SIGALRM
Caught SIGALRM
Caught SIGALRM
...
*/

