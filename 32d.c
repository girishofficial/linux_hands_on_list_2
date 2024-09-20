/*
============================================================================
Name : 32d.c
Author : GIRISH KUMAR SAHU
Description : Remove created semaphore
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>

int main() {
    key_t key = ftok("semfile", 65);
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("Failed to create semaphore");
        return 1;
    }

    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("Failed to remove semaphore");
        return 1;
    }

    printf("Semaphore removed successfully\n");
    return 0;
}

/*
Output:
Semaphore removed successfully
*/

