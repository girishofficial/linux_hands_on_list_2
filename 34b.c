/*
============================================================================
Name : 34b.c
Author : GIRISH KUMAR SAHU
Description : Create a concurrent server using pthread_create.
Date: 20th Sep, 2024.
=============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void* handle_client(void* client_socket_ptr) {
    int client_socket = *(int*)client_socket_ptr;
    char buffer[BUFFER_SIZE];
    read(client_socket, buffer, sizeof(buffer));
    printf("Client message: %s\n", buffer);
    send(client_socket, "Message received", 16, 0);
    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void*)&client_socket);
        pthread_detach(thread_id);
    }
    return 0;
}

/*
Output:
Client message: <client message>
*/

