/*
============================================================================
Name : 17c.c
Author : GIRISH KUMAR SAHU
Description : Execute ls -l | wc using fcntl.
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pipe(pipefd);
    
    if (fork() == 0) {
        fcntl(pipefd[1], F_SETFL, O_NONBLOCK);
        dup(pipefd[1]);
        close(pipefd[0]);
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        wait(NULL);
        fcntl(pipefd[0], F_SETFL, O_NONBLOCK);
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

