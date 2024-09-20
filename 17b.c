/*
============================================================================
Name : 17b.c
Author : GIRISH KUMAR SAHU
Description : Execute ls -l | wc using dup2.
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
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        wait(NULL);
        dup2(pipefd[0], STDIN_FILENO);
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

