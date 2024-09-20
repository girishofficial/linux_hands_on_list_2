/*
============================================================================
Name : 8d.c
Author : GIRISH KUMAR SAHU
Description : Catch SIGALRM (alarm system call)
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigalrm(int signum) {
    printf("Caught SIGALRM\n");
}

int main() {
    signal(SIGALRM, handle_sigalrm);
    alarm(2);
    while (1);
    return 0;
}

/*
Output:
Caught SIGALRM
*/

