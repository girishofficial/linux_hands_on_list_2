#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *fifo_path = "myfifo";
    char read_msg[100];

    int fd = open(fifo_path, O_RDONLY);
    read(fd, read_msg, sizeof(read_msg));
    printf("Received: %s\n", read_msg);
    close(fd);

    unlink(fifo_path);

    return 0;
}

