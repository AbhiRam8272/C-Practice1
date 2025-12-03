#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1024

void send_file(FILE *fp, int sockfd)
{
    char buffer[MAX];
    int n;

    printf("Sending file...\n");

    while ((n = fread(buffer, 1, MAX, fp)) > 0) {
        write(sockfd, buffer, n);
    }

    printf("File sent successfully.\n");
}

int main() {
    int sockfd = 0;
    struct sockaddr_in serv_addr;
    FILE *fp;
    char *filename = "sample.jpg";

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
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
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to server.\n");

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        close(sockfd);
        exit(1);
    }

    send_file(fp, sockfd);
    fclose(fp);
    close(sockfd);
    return 0;
}

