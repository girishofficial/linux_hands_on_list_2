/*
============================================================================
Name : 2.c
Author : Girish Kumar Sahu
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

void pRlimit(int resource,const char *name){
	struct rlimit lim;

	if(getrlimit(resource,&lim) == 0){
		printf("%s:\n", name);
		printf("Soft Limit: %ld \n", lim.rlim_cur);
		printf("Hard Limit: %ld \n", lim.rlim_max);
	}else{
		perror("didnt work");
	}
}

int main(){
	pRlimit(RLIMIT_CORE, "Size of Core file");
	pRlimit(RLIMIT_CPU,"CPU process can consume");
	pRlimit(RLIMIT_DATA, "Data segment size");
	pRlimit(RLIMIT_FSIZE, "Maximum size in byte a file can create");
	pRlimit(RLIMIT_NICE, "specifies ceiling to which process nice value can be rainsed");
	pRlimit(RLIMIT_STACK, "stack Size");
	
	return 0;
}

/* Output
 * Size of Core file:
Soft Limit: 0
Hard Limit: -1
CPU process can consume:
Soft Limit: -1
Hard Limit: -1
Data segment size:
Soft Limit: -1
Hard Limit: -1
Maximum size in byte a file can create:
Soft Limit: -1
Hard Limit: -1
specifies ceiling to which process nice value can be rainsed:
Soft Limit: 0
Hard Limit: 0
stack Size:
Soft Limit: 8388608
Hard Limit: -1
*/
