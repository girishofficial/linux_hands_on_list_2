/*
============================================================================
Name : 6.c
Author : Girish Kumar Sahu
Description : Write a simple program to create three threads.
Date: 17th Sep, 2024.
=============================================================================
*/


#include <stdio.h>
#include <pthread.h>

void* threadFunc(void* arg) {
    int thread_num = *(int*)arg;
    printf("Thread %d is running\n", thread_num);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int no_of_thread[3];

    for (int i = 0; i < 3; i++) {
        no_of_thread[i] = i + 1;
        pthread_create(&threads[i], NULL, threadFunc, &no_of_thread[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

/* Output
 * Thread 1 is running 
 * Thread 2 is running 
 * Thread 3 is running 
 */
