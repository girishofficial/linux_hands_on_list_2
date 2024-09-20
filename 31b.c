/*
============================================================================
Name : 31b.c
Author : GIRISH KUMAR SAHU
Description : Description of 31b.c
Date: 20th Sep, 2024.
=============================================================================
*/
/*
============================================================================
Name : 31a.c
Author : Girish Kumar Sahu
Description : Create a binary semaphore and initialize its value.
Date: 19th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key;
    int semid;

    key = ftok("progfile", 65);
    semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget failed");
        exit(1);
    }

    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl failed");
        exit(1);
    }

    printf("Binary semaphore created and initialized to 1
");

    return 0;
}

/*
Output:
Binary semaphore created and initialized to 1
*/
