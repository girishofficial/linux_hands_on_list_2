/*
============================================================================
Name : 5a.c
Author : GIRISH KUMAR SAHU
Description : Print max length of arguments for exec family of functions
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <limits.h>

int main() {
    printf("Max length of arguments to exec: %ld\n", sysconf(_SC_ARG_MAX));
    return 0;
}

/*
Output:
Max length of arguments to exec: 2097152 (varies based on system)
*/

