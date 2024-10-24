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

	printf("Sent Signal SIGINT to the process with PID %d\n",pid);
	return 0;
}
