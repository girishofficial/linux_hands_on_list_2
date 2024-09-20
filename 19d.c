/*
============================================================================
Name : 19d.c
Author : GIRISH KUMAR SAHU
Description : Create FIFO using mknod system call.
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    if (mknod("myfifo", S_IFIFO | 0666, 0) == -1) {
        perror("mknod failed");
        return 1;
    }
    printf("FIFO created using mknod system call\n");
    return 0;
}

/*
Output:
FIFO created using mknod system call
*/

