/*
============================================================================
Name : 8g.c
Author : GIRISH KUMAR SAHU
Description : Catch SIGPROF (setitimer system call)
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void handle_sigprof(int signum) {
    printf("Caught SIGPROF\n");
}

int main() {
    signal(SIGPROF, handle_sigprof);
    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_PROF, &timer, NULL);
    while (1);
    return 0;
}

/*
Output:
Caught SIGPROF
Caught SIGPROF
Caught SIGPROF
...
*/

