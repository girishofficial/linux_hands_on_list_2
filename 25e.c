/*
============================================================================
Name : 25e.c
Author : GIRISH KUMAR SAHU
Description : Print size of message queue
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <sys/msg.h>

int main() {
    int msqid = msgget(12345, 0666 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget failed");
        return 1;
    }

    struct msqid_ds buf;
    if (msgctl(msqid, IPC_STAT, &buf) == -1) {
        perror("msgctl failed");
        return 1;
    }

    printf("Queue size: %lu\n", buf.__msg_cbytes);
    return 0;
}

/*
Output:
Queue size: 0
*/

