#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int signalNO){
	printf("Signal Recived %d\n", signalNO);
	exit(EXIT_SUCCESS);
}

int main(){
	signal(SIGINT, handler);

	printf("Waiting for a signal (Press ctrl+C to send SIGINT)\n");

	while(1){
		pause();
	}
	return 0;
}

