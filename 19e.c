/*
============================================================================
Name : 19e.c
Author : GIRISH KUMAR SAHU
Description : Create FIFO using mkfifo library function.
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    if (mkfifo("myfifo", 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }
    printf("FIFO created using mkfifo library function\n");
    return 0;
}

/*
Output:
FIFO created using mkfifo library function
*/

