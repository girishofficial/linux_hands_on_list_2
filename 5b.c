/*
============================================================================
Name : 5b.c
Author : GIRISH KUMAR SAHU
Description : Print max number of simultaneous processes per user id
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <limits.h>

int main() {
    printf("Max number of processes per user id: %ld\n", sysconf(_SC_CHILD_MAX));
    return 0;
}

/*
Output:
Max number of processes per user id: 300 (varies based on system)
*/

