/*
============================================================================
Name : 12.c
Author : Girish Kumar Sahu
Description : Description of 12.c
Date: 20th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(){
    pid_t pid = fork();

    if(pid == 0) {
        printf("ChildPID = %d, ParentPID = %d
", getpid(), getppid());
        sleep(2);
        printf("Sending SIGKILL to parent (PID: %d)
", getppid());
        kill(getppid(), SIGKILL);
        sleep(2);
        printf("Child parent id should be one PID : %d
", getppid());
    } else {
        printf("Parent PID: %d, child PID is %d
", getpid(), pid);
        sleep(5);
    }

    return 0;
}

/*Output
 Parent PID: 13282, child PID is 13283
ChildPID = 13283, ParentPID = 13282
Sending SIGKILL to parent (PID: 13282)
Killed
Child parent id should be one PID : 2278
*/
