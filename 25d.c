/*
============================================================================
Name : 25d.c
Author : GIRISH KUMAR SAHU
Description : Print time of last change in message queue
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <sys/msg.h>
#include <time.h>

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

    printf("Last change: %s", ctime(&buf.msg_ctime));
    return 0;
}

/*
Output:
Last change: Thu Sep 20 11:30:00 2024
*/

