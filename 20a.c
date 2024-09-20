/*
============================================================================
Name : 20a.c
Author : GIRISH KUMAR SAHU
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 20th Sep, 2024.
=============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifo_path = "myfifo";
    char write_msg[] = "Hello FIFO writer!";

    mkfifo(fifo_path, 0666);
    
    int fd = open(fifo_path, O_WRONLY);
    write(fd, write_msg, strlen(write_msg) + 1);
    close(fd);

    return 0;
}
