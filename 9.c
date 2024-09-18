/*
============================================================================
Name : 9.c
Author : Girish Kumar Sahu
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call. 
Date: 19th Sep, 2024.
============================================================================
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handler(int sig) {
    printf("Caught SIGINT (Ctrl+C)\n");
}

int main(void) {
    signal(SIGINT, handler);
    printf("Catching SIGINT\n");
    sleep(10);
    printf("No SIGINT within 10 seconds\n");

    signal(SIGINT, SIG_IGN);
    printf("Ignoring SIGINT\n");
    sleep(10);
    printf("No SIGINT within 10 seconds\n");

    signal(SIGINT, SIG_DFL);
    printf("Default action for SIGINT\n");
    sleep(10);
    printf("No SIGINT within 10 seconds\n");

    return 0;
}

/*Output 
Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call. */
