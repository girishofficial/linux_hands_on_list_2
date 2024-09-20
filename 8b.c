/*
============================================================================
Name : 8b.c
Author : GIRISH KUMAR SAHU
Description : Catch SIGINT
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <signal.h>

void handle_sigint(int signum) {
    printf("Caught SIGINT\n");
}

int main() {
    signal(SIGINT, handle_sigint);
    while (1);
    return 0;
}

/*
Output (after pressing Ctrl+C):
Caught SIGINT
*/

