/*
============================================================================
Name : 8a.c
Author : GIRISH KUMAR SAHU
Description : Catch SIGSEGV
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigsegv(int signum) {
    printf("Caught SIGSEGV\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, handle_sigsegv);
    int *ptr = NULL;
    *ptr = 42;
    return 0;
}

/*
Output:
Caught SIGSEGV
*/

