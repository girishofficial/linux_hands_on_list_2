/*
============================================================================
Name : 24.c
Author : GIRISH KUMAR SAHU
Description : Write a program to create a message queue and print the key and message queue id.
Date: 20th Sep, 2024.
=============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid == -1) {
        perror("msgget failed");
        return 1;
    }

    printf("Key: %d
", key);
    printf("Message Queue ID: %d
", msgid);

    return 0;
}
