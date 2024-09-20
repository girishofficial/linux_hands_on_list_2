/*
============================================================================
Name : 17a.c
Author : GIRISH KUMAR SAHU
Description : Execute ls -l | wc using dup.
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pipe(pipefd);
    
    if (fork() == 0) {
        dup(pipefd[1]);
        close(pipefd[0]);
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        wait(NULL);
        dup(pipefd[0]);
        close(pipefd[0]);
        close(pipefd[1]);
        execlp("wc", "wc", NULL);
    }
    return 0;
}

/*
Output:
<output of ls -l followed by line count>
*/

