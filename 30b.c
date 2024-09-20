/*
============================================================================
Name : 30b.c
Author : GIRISH KUMAR SAHU
Description : Attach to shared memory in read-only mode.
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
    char *data = (char *)shmat(shmid, (void *)0, SHM_RDONLY);
    printf("Data in shared memory: %s\n", data);
    shmdt(data);
    return 0;
}

/*
Output:
Data in shared memory: Hello, this is shared memory!
*/

