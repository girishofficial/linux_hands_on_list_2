/*
============================================================================
Name : 7.c
Author : Girish Kumar Sahu
Description : Write a simple program to print the created thread ids.
Date: 19th Sep, 2024.
=============================================================================
*/


#include <stdio.h>
#include <pthread.h>

void* threadFunc(void* arg){
        printf("Thread ID: %lu\n", pthread_self());
	return NULL;
}

int main(){
	pthread_t t[3];
	for(int i = 0;i<3;i++){
		pthread_create(&t[i],NULL,threadFunc,NULL);
	}
	for(int i = 0;i<3;i++){
		pthread_join(t[i],NULL);
	}

	return 0;
}

/*Output
Thread ID: 126364243986112
Thread ID: 126364233500352
Thread ID: 126364223014592
*/
