#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // create one child process
    pid = fork();

    if (pid < 0) {
        // fork failed
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        // child process
        printf("Hello from child! PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else {
        // parent process
        printf("Hello from parent! PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}

