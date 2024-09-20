/*
============================================================================
Name        : 18.c
Author      : GIRISH KUMAR SAHU
Description : Write a program to find out total number of directories on the pwd.
              Execute `ls -l | grep ^d | wc` using dup2.
Date        : 20th Sep, 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe1[2], pipe2[2];

    pipe(pipe1);
    pipe(pipe2);

    if (fork() == 0) {
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        execlp("ls", "ls", "-l", NULL);
        exit(1);
    }

    if (fork() == 0) {
        dup2(pipe1[0], STDIN_FILENO);
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe1[1]);
        close(pipe1[0]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("grep", "grep", "^d", NULL);
        exit(1);
    }

    close(pipe1[0]);
    close(pipe1[1]);
    dup2(pipe2[0], STDIN_FILENO);
    close(pipe2[1]);
    close(pipe2[0]);
    execlp("wc", "wc", "-l", NULL);
    return 1;
}

/*Output 0*/
