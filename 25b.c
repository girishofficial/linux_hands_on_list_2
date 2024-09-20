/*
============================================================================
Name : 25b.c
Author : GIRISH KUMAR SAHU
Description : Print message queue UID and GID
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

    printf("UID: %d\n", buf.msg_perm.uid);
    printf("GID: %d\n", buf.msg_perm.gid);
    return 0;
}

/*
Output:
UID: 1000
GID: 1000
*/

