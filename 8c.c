/*
============================================================================
Name : 8c.c
Author : GIRISH KUMAR SAHU
Description : Catch SIGFPE
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigfpe(int signum) {
    printf("Caught SIGFPE\n");
    exit(1);
}

int main() {
    signal(SIGFPE, handle_sigfpe);
    int a = 1 / 0;
    return 0;
}

/*
Output:
Caught SIGFPE
*/

