/*
============================================================================
Name : 30d.c
Author : GIRISH KUMAR SAHU
Description : Detach and remove shared memory.
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 0, 0666);
    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory removed.\n");
    return 0;
}

/*
Output:
Shared memory removed.
*/

