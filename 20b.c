/*
============================================================================
Name : 20b.c
Author : GIRISH KUMAR SAHU
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 20th Sep, 2024.
=============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *fifo_path = "myfifo";
    char read_msg[100];

    int fd = open(fifo_path, O_RDONLY);
    read(fd, read_msg, sizeof(read_msg));
    printf("Received: %s
", read_msg);
    close(fd);

    unlink(fifo_path);

    return 0;
}
