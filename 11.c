/*
============================================================================
Name : 11.c
Author : Girish Kumar Sahu
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
signal - Use signal system call. 
Date: 19th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int signalNo) {
	if(signalNo == SIGFPE){
		printf("Caught SIGFE \n");
		exit(1);
	}
	else if(signalNo == SIGINT){
		printf("Caught SIGINT (Ctrl+C)\n");
		exit(1);
	}
	else if(signalNo == SIGSEGV){
		printf("Caught SIGSEGV (segmentation fault)\n");
		exit(1);
	}
}

int main(){
	struct sigaction act;

	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGFPE,&act,NULL);
	sigaction(SIGINT,&act,NULL);
	sigaction(SIGSEGV,&act,NULL);

	while(1){
	//	printf("press ctrl+c for sigint\n ");
	//	sleep(1);
	
	/*int x = 5/0; this is to get SIGFPE trigger*/
	int *ptr = NULL;
	*ptr = 42; /*this will give SIGPE*/
	}
	return 0;
}

/*output 
 Caught SIGSEGV*/
