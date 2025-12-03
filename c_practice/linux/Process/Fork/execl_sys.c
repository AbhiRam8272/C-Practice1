#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h>   

int main() {
    
    char *args[] = {"pw-top", NULL};

    pid_t pid = fork(); 

    if (pid == -1) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Child is running 'ls -l'...\n");

        execvp(args[0], args);
        perror("execvp failed");
        exit(1); 

    } else {        
        printf("Parent is waiting for the child to finish.\n");
        wait(NULL);
        printf("Child process finished. Parent is continuing.\n");
    }

    return 0;
}
