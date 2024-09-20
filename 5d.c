/*
============================================================================
Name : 5d.c
Author : GIRISH KUMAR SAHU
Description : Print max number of open files
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <limits.h>

int main() {
    printf("Max number of open files: %ld\n", sysconf(_SC_OPEN_MAX));
    return 0;
}

/*
Output:
Max number of open files: 1024 (varies based on system)
*/

