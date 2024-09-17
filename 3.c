/*
============================================================================
Name : 3.c
Author : Girish Kumar Sahu
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

/*int main(){
	struct rlimit lim;

	lim.rlim_cur = 10;
	lim.rlim_max = 12;

	if(setrlimit(RLIMIT_NICE, &lim) == 0){
		printf("Succefully changed the soft and hardlimit for priority\n");
	} else{
		perror("failed setrlimit\n");
		return 1;
	}
	int current_prio = getpriority(PRIO_PROCESS,0); 0 refers to the current process
	printf("current priority is : %d\n",current_prio);

	if(setpriority(PRIO_PROCESS, 0, 5) == 0){
		printf("Successfully set nice value to 5\n");
	}

	if(setpriority(PRIO_PROCESS, 0,15)==0){
		printf("Successfully set nice value to 15\n");
	}else{
		perror("failed to set nice value as limit excceded");
	}

	return 0;
}*/

int main(){
	struct rlimit lim;

	lim.rlim_cur = 5;
	lim.rlim_max = 10;

	if(setrlimit(RLIMIT_CPU, &lim) == 0){
		printf("Succefully changed cpu softlimit and hardlimit.");
	}else{
		perror("failed to set cpu limit");
		return 1;
	}

	while(1){
		printf("running...\n");
		sleep(1);
	}

	return 0;

}

/*Output
 * running...
 * running...
 * running...
 * ....
*/
