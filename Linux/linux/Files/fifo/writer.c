#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fd;
    char *fifoPath = "/home/abyys/C-Practice1/Linux/linux/Files/fifo/myfifo";


    char message[100];
    printf("Enter message to send: ");
    fgets(message, sizeof(message), stdin);

    fd = open(fifoPath, O_WRONLY);
    write(fd, message, sizeof(message));
    close(fd);

    return 0;
}

