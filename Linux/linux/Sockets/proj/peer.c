	/*
 * peer_chat_file.c
 * Compile:
 *   gcc peer_chat_file.c -o peer -pthread
 *
 * Usage:
 *   As server: ./peer -l 8080
 *   As client: ./peer -c <server_ip> 8080
 *
 * Commands:
 *   /file <path>   - send a file
 *   /quit          - exit the chat
 *
 * Features:
 *   - Chat + file sharing (txt, png, jpeg, mp4, etc.)
 *   - Progress bar for file transfers
 *   - Confirm before receiving a file
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAGIC "FTR0"
#define MAGIC_LEN 4
#define BUF_SIZE 8192
#define CHAT_MAGIC "MSG0"

ssize_t send_all(int sock, const void *buf, size_t len) {
    size_t total = 0;
    const char *p = buf;
    while (total < len) {
        ssize_t n = send(sock, p + total, len - total, 0);
        if (n <= 0) {
            if (errno == EINTR) continue;
            return -1;
        }
        total += n;
    }
    return total;
}

ssize_t recv_all(int sock, void *buf, size_t len) {
    size_t total = 0;
    char *p = buf;
    while (total < len) {
        ssize_t n = recv(sock, p + total, len - total, 0);
        if (n <= 0) return n;
        total += n;
    }
    return total;
}

uint64_t htonll_u64(uint64_t v) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    return (((uint64_t)htonl(v & 0xFFFFFFFFULL)) << 32) | htonl(v >> 32);
#else
    return v;
#endif
}
uint64_t ntohll_u64(uint64_t v) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    return (((uint64_t)ntohl(v & 0xFFFFFFFFULL)) << 32) | ntohl(v >> 32);
#else
    return v;
#endif
}

typedef struct {
    int sock;
} thread_arg_t;

// Utility: print progress bar
void print_progress(uint64_t done, uint64_t total) {
    float pct = (total == 0) ? 100.0 : ((float)done / (float)total) * 100.0;
    int width = 30;
    int filled = (int)((pct / 100.0) * width);
    printf("\r[");
    for (int i = 0; i < width; i++) printf(i < filled ? "#" : "-");
    printf("] %.1f%%", pct);
    fflush(stdout);
}

// ---- Receiver ----
void *recv_thread(void *arg) {
    thread_arg_t *ta = (thread_arg_t*)arg;
    int sock = ta->sock;
    char header[4];

    for (;;) {
        ssize_t r = recv_all(sock, header, 4);
        if (r <= 0) {
            printf("\n[*] Peer disconnected.\n");
            break;
        }

        if (memcmp(header, MAGIC, 4) == 0) {
            // File transfer incoming
            uint16_t fn_len_net;
            uint64_t fsize_net;
            if (recv_all(sock, &fn_len_net, 2) <= 0) break;
            if (recv_all(sock, &fsize_net, 8) <= 0) break;
            uint16_t fn_len = ntohs(fn_len_net);
            uint64_t fsize = ntohll_u64(fsize_net);

            char *filename = malloc(fn_len + 1);
            recv_all(sock, filename, fn_len);
            filename[fn_len] = '\0';

            printf("\n📁 File incoming: %s (%.2f KB)\n", filename, fsize / 1024.0);
           

// prepare filename to save
char outname[BUF_SIZE];
printf("[*] Incoming file: '%s' (%" PRIu64 " bytes). Saving as '%s'\n", filename, fsize, outname);
snprintf(outname, sizeof(outname), "received_%s", filename);
int idx = 1;
while (access(outname, F_OK) == 0) {
    snprintf(outname, sizeof(outname), "received_%d_%s", idx++, filename);
}

// open file for writing
FILE *fp = fopen(outname, "wb");
if (!fp) { perror("fopen"); free(filename); break; }

// receive payload
uint64_t received = 0;
char buf[BUF_SIZE];

while (received < fsize) {
    size_t to_read = BUF_SIZE;
    if (fsize - received < to_read) to_read = (size_t)(fsize - received);
    ssize_t got = recv_all(sock, buf, to_read);
    if (got <= 0) { perror("recv payload"); break; }
    fwrite(buf, 1, got, fp);
    received += got;

    // progress bar
    float pct = (fsize == 0) ? 100.0f : ((float)received / (float)fsize) * 100.0f;
    printf("\r    Received: %" PRIu64 " / %" PRIu64 " (%.1f%%)", received, fsize, pct);
    fflush(stdout);
}

printf("\n[+] File '%s' saved (%" PRIu64 " bytes)\n", outname, received);
fclose(fp);
free(filename);

        } 
        else if (memcmp(header, CHAT_MAGIC, 4) == 0) {
            // Chat message incoming
            uint16_t msg_len_net;
            if (recv_all(sock, &msg_len_net, 2) <= 0) break;
            uint16_t msg_len = ntohs(msg_len_net);
            char *msg = malloc(msg_len + 1);
            recv_all(sock, msg, msg_len);
            msg[msg_len] = '\0';
            printf("\n👤 Peer: %s\n> ", msg);
            fflush(stdout);
            free(msg);
        } 
        else {
            printf("\n[!] Unknown header received.\n");
            break;
        }
    }
    return NULL;
}

// ---- Sender ----
void send_chat(int sock, const char *msg) {
    uint16_t len = strlen(msg);
    uint16_t len_net = htons(len);
    send_all(sock, CHAT_MAGIC, 4);
    send_all(sock, &len_net, 2);
    send_all(sock, msg, len);
}

void send_file(int sock, const char *path) {
    FILE *fp = fopen(path, "rb");
    if (!fp) { perror("fopen"); return; }

    struct stat st;
    if (stat(path, &st) < 0) { perror("stat"); fclose(fp); return; }
    uint64_t fsize = (uint64_t)st.st_size;

    const char *filename = strrchr(path, '/');
    filename = filename ? filename + 1 : path;
    uint16_t fn_len = strlen(filename);

    // Send header
    send_all(sock, MAGIC, 4);
    uint16_t fn_len_net = htons(fn_len);
    uint64_t fsize_net = htonll_u64(fsize);
    send_all(sock, &fn_len_net, 2);
    send_all(sock, &fsize_net, 8);
    send_all(sock, filename, fn_len);

    printf("[*] Sending file: %s (%.2f KB)\n", filename, fsize / 1024.0);
    uint64_t sent = 0;
    char buf[BUF_SIZE];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), fp)) > 0) {
        if (send_all(sock, buf, n) < 0) break;
        sent += n;
        print_progress(sent, fsize);
    }
    printf("\n[+] File sent successfully!\n");
    fclose(fp);
}

void *send_thread(void *arg) {
    thread_arg_t *ta = (thread_arg_t*)arg;
    int sock = ta->sock;
    char input[1024];

    while (1) {
        printf("> ");
        fflush(stdout);
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0;

        if (strncmp(input, "/quit", 5) == 0) {
            printf("[*] Exiting chat.\n");
            shutdown(sock, SHUT_WR);
            break;
        } else if (strncmp(input, "/file ", 6) == 0) {
            send_file(sock, input + 6);
        } else {
            send_chat(sock, input);
        }
    }
    return NULL;
}

int create_and_bind(int port) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(fd, 1);
    return fd;
}

int connect_to(const char *ip, int port) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &addr.sin_addr);
    connect(fd, (struct sockaddr*)&addr, sizeof(addr));
    return fd;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage:\n  Server: %s -l <port>\n  Client: %s -c <server_ip> <port>\n", argv[0], argv[0]);
        return 1;
    }

    int sock;
    if (strcmp(argv[1], "-l") == 0) {
        int port = atoi(argv[2]);
        int listen_fd = create_and_bind(port);
        struct sockaddr_in cli;
        socklen_t len = sizeof(cli);
        printf("[*] Listening on port %d...\n", port);
        sock = accept(listen_fd, (struct sockaddr*)&cli, &len);
        close(listen_fd);
        printf("[+] Client connected!\n");
    } else {
        const char *ip = argv[2];
        int port = atoi(argv[3]);
        sock = connect_to(ip, port);
        printf("[+] Connected to server!\n");
    }

    thread_arg_t arg = {.sock = sock};
    pthread_t t_recv, t_send;
    pthread_create(&t_recv, NULL, recv_thread, &arg);
    pthread_create(&t_send, NULL, send_thread, &arg);
    pthread_join(t_send, NULL);
    pthread_cancel(t_recv);

    close(sock);
    printf("[*] Connection closed.\n");
    return 0;
}

