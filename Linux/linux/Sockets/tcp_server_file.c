#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define SIZE 1024

void write_file(int new_sock);

int main() {
    int server_fd, new_sock;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket error");
        exit(1);
    }
    printf("[+]Server socket created.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind error");
        exit(1);
    }
    printf("[+]Bind to port %d\n", PORT);

    if (listen(server_fd, 10) == 0)
        printf("Listening...\n");
    else {
        perror("Listen error");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    new_sock = accept(server_fd, (struct sockaddr*)&new_addr, &addr_size);
    if (new_sock < 0) {
        perror("Accept error");
        exit(1);
    }
    printf("[+]Client connected.\n");

    write_file(new_sock);
    printf("[+]File received successfully.\n");

    close(new_sock);
    close(server_fd);
    printf("[+]Server disconnected.\n");

    return 0;
}

void write_file(int new_sock) {
    FILE *fp;
    char buffer[SIZE];
    int n;

    fp = fopen("received_file.png", "wb");  // IMPORTANT: use binary mode
    if (fp == NULL) {
        perror("File open error");
        exit(1);
    }

    while ((n = recv(new_sock, buffer, SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), n, fp);
    }

    fclose(fp);
}

