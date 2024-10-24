#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    struct rlimit limit;

    getrlimit(RLIMIT_NOFILE, &limit);
    printf("Max open files: %lu\n", limit.rlim_cur);

    int pipefd[2];
    pipe(pipefd);
    int flags = fcntl(pipefd[0], F_GETFL);
    
    printf("Pipe size (not directly available): %d\n", flags);

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}


