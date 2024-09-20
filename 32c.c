/*
============================================================================
Name : 32c.c
Author : GIRISH KUMAR SAHU
Description : Protect multiple pseudo resources using counting semaphore
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

int resource1 = 5, resource2 = 3;
sem_t sem_resources;

void* access_resource(void* arg) {
    sem_wait(&sem_resources);
    printf("Accessing resource: Resource1 = %d, Resource2 = %d\n", resource1--, resource2--);
    sem_post(&sem_resources);
    return NULL;
}

int main() {
    pthread_t tid[4];
    sem_init(&sem_resources, 0, 2);  // Allowing 2 threads to access resources simultaneously

    for (int i = 0; i < 4; i++) {
        pthread_create(&tid[i], NULL, access_resource, NULL);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&sem_resources);
    return 0;
}

/*
Output:
Accessing resource: Resource1 = 5, Resource2 = 3
Accessing resource: Resource1 = 4, Resource2 = 2
Accessing resource: Resource1 = 3, Resource2 = 1
Accessing resource: Resource1 = 2, Resource2 = 0
*/

