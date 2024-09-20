/*
============================================================================
Name : 28.c
Author : Girish Kumar Sahu
Description : Change the existing message queue permission.
Date: 19th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds msg_info;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        return 1;
    }

    if (msgctl(msgid, IPC_STAT, &msg_info) == -1) {
        perror("msgctl IPC_STAT failed");
        return 1;
    }

    printf("Current Permissions: %o\n", msg_info.msg_perm.mode);

    msg_info.msg_perm.mode = 0644; // Change permissions to read/write for owner and read for others

    if (msgctl(msgid, IPC_SET, &msg_info) == -1) {
        perror("msgctl IPC_SET failed");
        return 1;
    }

    printf("Permissions changed to: %o\n", msg_info.msg_perm.mode);

    return 0;
}

/*
Output:
Current Permissions: 666
Permissions changed to: 644
*/

