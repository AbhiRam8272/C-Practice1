#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX];
    char message[MAX];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IP
    if (inet_pton(AF_INET, "192.168.68.105", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(1);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to server.\n");

    while (1) {
        printf("You: ");
        fgets(message, MAX, stdin);
        send(sock, message, strlen(message), 0);

        if (strncmp(message, "exit", 4) == 0) {
            printf("Client exiting...\n");
            break;
        }

        memset(buffer, 0, MAX);
        int valread = read(sock, buffer, MAX);
        if (valread <= 0) break;
        printf("Server: %s\n", buffer);
    }

    close(sock);
    return 0;
}
