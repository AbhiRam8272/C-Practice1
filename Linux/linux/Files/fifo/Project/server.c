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

    char buffer[100];

    printf("Server started. Waiting for messages...\n");

    while (1) {
        fd_read = open(fifo1, O_RDONLY);
        read(fd_read, buffer, sizeof(buffer));
        close(fd_read);

        printf("\nClient: %s\n", buffer);

        if (strncmp("exit", buffer, 4) == 0)
            break;

        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);

        fd_write = open(fifo2, O_WRONLY);
        write(fd_write, buffer, strlen(buffer) + 1);
        close(fd_write);

        if (strncmp("exit", buffer, 4) == 0)
            break;
    }

    unlink(fifo1);
    unlink(fifo2);
    return 0;
}
