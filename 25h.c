/*
============================================================================
Name : 25h.c
Author : GIRISH KUMAR SAHU
Description : Print PID of msgsnd and msgrcv
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

    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);
    return 0;
}

/*
Output:
PID of last msgsnd: 1234
PID of last msgrcv: 5678
*/

