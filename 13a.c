/*
============================================================================
Name : 13a.c
Author : GIRISH KUMAR SAHU
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 20th Sep, 2024.
=============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int signalNO){
	printf("Signal Recived %d
", signalNO);
	exit(EXIT_SUCCESS);
}

int main(){
	signal(SIGINT, handler);

	printf("Waiting for a signal (Press ctrl+C to send SIGINT)
");

	while(1){
		pause();
	}
	return 0;
}
