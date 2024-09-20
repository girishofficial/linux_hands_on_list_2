/*
============================================================================
Name : 5c.c
Author : GIRISH KUMAR SAHU
Description : Print number of clock ticks per second
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Number of clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));
    return 0;
}

/*
Output:
Number of clock ticks per second: 100 (varies based on system)
*/

