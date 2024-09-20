/*
============================================================================
Name : 32b.c
Author : GIRISH KUMAR SAHU
Description : Protect shared memory using semaphore to prevent concurrent write
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

int shared_mem = 0;
sem_t sem;

void* write_shared_mem(void* arg) {
    sem_wait(&sem);
    shared_mem++;
    printf("Shared Memory updated to: %d\n", shared_mem);
    sem_post(&sem);
    return NULL;
}

int main() {
    pthread_t tid[5];
    sem_init(&sem, 0, 1);

    for (int i = 0; i < 5; i++) {
        pthread_create(&tid[i], NULL, write_shared_mem, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&sem);
    return 0;
}

/*
Output:
Shared Memory updated to: 1
Shared Memory updated to: 2
Shared Memory updated to: 3
Shared Memory updated to: 4
Shared Memory updated to: 5
*/

