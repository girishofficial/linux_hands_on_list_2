/*
============================================================================
Name : 32a.c
Author : GIRISH KUMAR SAHU
Description : Ticket number creation using semaphore to protect critical section
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

int ticket_no = 1;
sem_t sem;

void* create_ticket(void* arg) {
    sem_wait(&sem);
    printf("Ticket Number: %d\n", ticket_no++);
    sem_post(&sem);
    return NULL;
}

int main() {
    pthread_t tid[5];
    sem_init(&sem, 0, 1);

    for (int i = 0; i < 5; i++) {
        pthread_create(&tid[i], NULL, create_ticket, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&sem);
    return 0;
}

/*
Output:
Ticket Number: 1
Ticket Number: 2
Ticket Number: 3
Ticket Number: 4
Ticket Number: 5
*/

