/*
============================================================================
Name : 16.c
Author : GIRISH KUMAR SAHU
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 20th Sep, 2024.
=============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int p1[2];
    int p2[2];
    pid_t pid;
    char msg_from_parent[] = "Hello from parent!";
    char msg_from_child[] = "Hello from child!";
    char buffer[100];

    pipe(p1);
    pipe(p2);
    
    pid = fork();
    
    if (pid > 0) {
        close(p1[0]);
        close(p2[1]);
        write(p1[1], msg_from_parent, strlen(msg_from_parent) + 1);
        read(p2[0], buffer, sizeof(buffer));
        printf("Parent received: %s
", buffer);
        close(p1[1]);
        close(p2[0]);
    } else {
        close(p1[1]);
        close(p2[0]);
        read(p1[0], buffer, sizeof(buffer));
        printf("Child received: %s
", buffer);
        write(p2[1], msg_from_child, strlen(msg_from_child) + 1);
        close(p1[0]);
        close(p2[1]);
    }

    return 0;
}
