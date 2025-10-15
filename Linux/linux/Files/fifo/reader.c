#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fd;
    char *fifoPath = "/home/abyys/C-Practice1/Linux/linux/Files/fifo/myfifo";
    char buffer[100];

    mkfifo(fifoPath, 0666);

    printf("Waiting for message...\n");
    fd = open(fifoPath, O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    printf("Received message: %s\n", buffer);
    close(fd);

    return 0;
}

