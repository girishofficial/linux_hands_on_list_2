/*
============================================================================
Name : 5e.c
Author : GIRISH KUMAR SAHU
Description : Print size of a page
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Size of a page: %ld bytes\n", sysconf(_SC_PAGESIZE));
    return 0;
}

/*
Output:
Size of a page: 4096 bytes (varies based on system)
*/

