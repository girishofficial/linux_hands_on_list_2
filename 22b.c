/*
============================================================================
Name : 22b.c
Author : GIRISH KUMAR SAHU
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 20th Sep, 2024.
=============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifo1 = "/tmp/myfifo1";
    const char *fifo2 = "/tmp/myfifo2";
    char write_msg[100];
    char read_msg[100];

    int fd1 = open(fifo1, O_RDONLY);
    read(fd1, read_msg, sizeof(read_msg));
    printf("FIFO Reader received: %s
", read_msg);
    close(fd1);

    printf("FIFO Reader: Enter message to send back: ");
    fgets(write_msg, sizeof(write_msg), stdin);
    
    int fd2 = open(fifo2, O_WRONLY);
    write(fd2, write_msg, strlen(write_msg) + 1);
    close(fd2);

    return 0;
}
