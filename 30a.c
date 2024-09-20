/*
============================================================================
Name : 30a.c
Author : GIRISH KUMAR SAHU
Description : Create shared memory and write data to it.
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    char *data = (char *)shmat(shmid, (void *)0, 0);
    strcpy(data, "Hello, this is shared memory!");
    printf("Data written: %s\n", data);
    shmdt(data);
    return 0;
}

/*
Output:
Data written: Hello, this is shared memory!
*/


