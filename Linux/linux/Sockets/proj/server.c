#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/stat.h>

#define PORT 8080
#define SIZE 1024
#define BUF_SIZE (1 * 1024 * 1024)

int client_sock;

int send_all(int sock, const void *buf, int len) {
    int total = 0;
    int sent;
    const char *ptr = (const char *)buf;
    while (total < len) {
        sent = send(sock, ptr + total, len - total, 0);
        if (sent <= 0) return -1;
        total += sent;
    }
    return total;
}

int recv_all(int sock, void *buf, int len) {
    int total = 0;
    int recvd;
    char *ptr = (char *)buf;
    while (total < len) {
        recvd = recv(sock, ptr + total, len - total, 0);
        if (recvd <= 0) return -1;
        total += recvd;
    }
    return total;
}

void send_file(const char *filename);
void receive_file();
void *send_data(void *arg);
void *receive_data(void *arg);

int main() {
    int server_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pthread_t send_thread, recv_thread;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) { perror("Socket error"); exit(1); }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind error"); exit(1);
    }

    if (listen(server_sock, 1) < 0) { perror("Listen error"); exit(1); }

    printf("[+] Server listening on port %d...\n", PORT);
    addr_size = sizeof(client_addr);

    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
    if (client_sock < 0) { perror("Accept error"); exit(1); }

    printf("[+] Client connected.\n");

    pthread_create(&send_thread, NULL, send_data, NULL);
    pthread_create(&recv_thread, NULL, receive_data, NULL);

    pthread_join(send_thread, NULL);
    pthread_join(recv_thread, NULL);

    close(client_sock);
    close(server_sock);
    return 0;
}

void *send_data(void *arg) {
    char msg[SIZE];
    while (1) {
        fgets(msg, SIZE, stdin);
        if (strncmp(msg, "/send ", 6) == 0) {
            char filename[256];
            sscanf(msg + 6, "%s", filename);
            send_all(client_sock, "FILE", 4);
            send_file(filename);
        } else {
            send_all(client_sock, msg, strlen(msg));
        }

        if (strncmp(msg, "/exit", 5) == 0) {
            printf("[+] Closing chat.\n");
            break;
        }
    }
    return NULL;
}

void *receive_data(void *arg) {
    char buffer[SIZE];
    while (1) {
        int n = recv(client_sock, buffer, 4, 0);
        if (n <= 0) break;

        if (strncmp(buffer, "FILE", 4) == 0) {
            receive_file();
        } else {
            // receive normal message
            int msg_len = n;
            msg_len += recv(client_sock, buffer + n, SIZE - n, 0);
            buffer[msg_len] = '\0';
            printf("Client: %s", buffer);
        }
    }
    return NULL;
}

void send_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("File open error");
        return;
    }

    struct stat st;
    stat(filename, &st);
    long filesize = st.st_size;
    int fname_len = strlen(filename);

    send_all(client_sock, &fname_len, sizeof(int));
    send_all(client_sock, filename, fname_len);
    send_all(client_sock, &filesize, sizeof(long));

    char buffer[BUF_SIZE];
    long total_sent = 0;
    while (!feof(fp)) {
        int bytes = fread(buffer, 1, SIZE, fp);
        if (bytes <= 0) break;
        send_all(client_sock, buffer, bytes);
        total_sent += bytes;
        printf("\r[+] Progress: %.2f%%", (float)total_sent / filesize * 100);
        fflush(stdout);
    }
    fclose(fp);
    printf("\n[+] File sent: %s\n", filename);
}

void receive_file() {
    int fname_len;
    recv_all(client_sock, &fname_len, sizeof(int));

    char filename[256];
    recv_all(client_sock, filename, fname_len);
    filename[fname_len] = '\0';

    long filesize;
    recv_all(client_sock, &filesize, sizeof(long));

    FILE *fp = fopen(filename, "wb");
    if (!fp) { perror("File create error"); return; }

    char buffer[BUF_SIZE];
    long total_received = 0;
    while (total_received < filesize) {
        int bytes_to_read = (filesize - total_received) > SIZE ? SIZE : (filesize - total_received);
        int n = recv_all(client_sock, buffer, bytes_to_read);
        if (n <= 0) break;
        fwrite(buffer, 1, n, fp);
        total_received += n;
        printf("\r[+] Receiving: %.2f%%", (float)total_received / filesize * 100);
        fflush(stdout);
    }
    fclose(fp);
    printf("\n[+] File received: %s\n", filename);
}

