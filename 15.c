/*
============================================================================
Name : 15.c
Author : GIRISH KUMAR SAHU
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 20th Sep, 2024.
=============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char write_m[] = "Written using parent process";
    char read_m[100];

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {
        close(fd[0]);
        write(fd[1], write_m, strlen(write_m) + 1);
        close(fd[1]);
    } else {
        close(fd[1]);
        read(fd[0], read_m, sizeof(read_m));
        printf("Child process received: %s
", read_m);
        close(fd[0]);
    }

    return 0;
}
