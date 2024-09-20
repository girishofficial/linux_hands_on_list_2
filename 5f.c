/*
============================================================================
Name : 5f.c
Author : GIRISH KUMAR SAHU
Description : Print total number of pages in physical memory
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Total number of pages in physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
    return 0;
}

/*
Output:
Total number of pages in physical memory: 3834880 (varies based on system)
*/

