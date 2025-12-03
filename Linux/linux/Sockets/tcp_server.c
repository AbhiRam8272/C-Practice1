#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX];
    char message[MAX];

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    // Listen for client
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(1);
    }
    printf("Server waiting for connection...\n");

    // Accept connection
    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        perror("Accept failed");
        exit(1);
    }
    printf("Client connected.\n");

    while (1) {
        memset(buffer, 0, MAX);
        int valread = read(new_socket, buffer, MAX);
        if (valread <= 0) break;

        printf("Client: %s\n", buffer);

        printf("You: ");
        fgets(message, MAX, stdin);
        send(new_socket, message, strlen(message), 0);

        if (strncmp(message, "exit", 4) == 0) {
            printf("Server exiting...\n");
            break;
        }
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
