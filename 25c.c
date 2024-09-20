/*
============================================================================
Name : 25c.c
Author : GIRISH KUMAR SAHU
Description : Print time of last message sent and received
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

    printf("Last message sent: %s", ctime(&buf.msg_stime));
    printf("Last message received: %s", ctime(&buf.msg_rtime));
    return 0;
}

/*
Output:
Last message sent: Thu Sep 20 11:25:10 2024
Last message received: Thu Sep 20 11:25:10 2024
*/

