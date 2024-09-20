/*
============================================================================
Name : 23.c
Author : GIRISH KUMAR SAHU
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 20th Sep, 2024.
=============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    struct rlimit limit;

    getrlimit(RLIMIT_NOFILE, &limit);
    printf("Max open files: %lu
", limit.rlim_cur);

    int pipefd[2];
    pipe(pipefd);
    int flags = fcntl(pipefd[0], F_GETFL);
    
    printf("Pipe size (not directly available): %d
", flags);

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}
