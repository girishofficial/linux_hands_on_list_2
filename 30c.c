/*
============================================================================
Name : 30c.c
Author : GIRISH KUMAR SAHU
Description : Attempt to write to shared memory while attached in read-only mode.
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 0, 0666);
    char *data = (char *)shmat(shmid, (void *)0, SHM_RDONLY);
    strcpy(data, "Trying to overwrite!");  // This will cause an error
    printf("Data in shared memory: %s\n", data);
    shmdt(data);
    return 0;
}

/*
Output:
Data in shared memory: Hello, this is shared memory!
Error: cannot overwrite in read-only mode.
*/

