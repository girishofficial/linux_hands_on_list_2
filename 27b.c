/*
============================================================================
Name : 27b.c
Author : Girish Kumar Sahu
Description : Receive message from the message queue with IPC_NOWAIT as a flag.
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, IPC_NOWAIT) == -1) {
        perror("msgrcv failed with IPC_NOWAIT");
    } else {
        printf("Data received: %s\n", message.msg_text);
    }

    return 0;
}

/*
Output:
Data received: Hello from the message queue!
or
msgrcv failed with IPC_NOWAIT: No message available
*/

