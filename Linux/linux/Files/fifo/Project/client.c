#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fd_read, fd_write;
    char *fifo1 = "/home/abyys/C-Practice1/Linux/linux/Files/fifo/Project/fifo1";  
    char *fifo2 = "/home/abyys/C-Practice1/Linux/linux/Files/fifo/Project/fifo2";  

    mkfifo(fifo1,0666);
    mkfifo(fifo2,0666);

    char buffer[100];

    printf("Client started. Type messages...\n");

    while (1) {
        printf("Client: ");
        fgets(buffer, sizeof(buffer), stdin);

        fd_write = open(fifo1, O_WRONLY);
        write(fd_write, buffer, strlen(buffer) + 1);
        close(fd_write);

        if (strncmp("exit", buffer, 4) == 0)
            break;

        fd_read = open(fifo2, O_RDONLY);
        read(fd_read, buffer, sizeof(buffer));
        close(fd_read);

        printf("Server: %s\n", buffer);

        if (strncmp("exit", buffer, 4) == 0)
            break;
    }

    return 0;
}

