/*
============================================================================
Name : 4.c
Author : Girish Kumar Sahu
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter. 
Date: 19th Sep, 2024.
=============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <x86intrin.h>

int main(){
	uint64_t start,end;
	pid_t ppid;
	int cnt;

	start = __rdtsc();

	for(cnt = 0;cnt<100;cnt++){
		ppid = getppid();
	}

	end = __rdtsc();

	printf("Time taken for 100 getppid() : %lu CPU cycles\n", end-start);
	
	return 0;
}

/* output
 *Time taken for 100 getppid() : 138190 CPU cycles
*/
