/*
============================================================================
Name : 13b.c
Author : GIRISH KUMAR SAHU
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 20th Sep, 2024.
=============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(){
	pid_t pid;

	printf("Enter PID for sending the signal: ");
	scanf("%d",&pid);

	if(kill(pid,SIGINT)==-1){
			perror("Error Sending Signal");
			exit(EXIT_FAILURE);
	}

	printf("Sent Signal SIGINT to the process with PID %d
",pid);
	return 0;
}
