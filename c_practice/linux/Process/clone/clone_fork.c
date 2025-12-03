#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int v=500;
char *p="hello";

int child_fn(void *arg) {
    sleep(2);
    v=200;
    printf("Child: v is = %d\n", v);
    printf("Child: p is = %s\n", p);
    printf("Child: got value = %d\n", *(int*)arg);
    return 0;
}

int main() {
    int value = 100;
    char *stack = malloc(1024*1024); // child stack
    pid_t pid = clone(child_fn, stack+1024*1024, SIGCHLD, &value);

//    waitpid(pid, NULL, 0);
    printf("Parent: v is = %d\n", v);
    printf("Parent: p is = %s\n", p);
    printf("Parent: value = %d\n", value);
    sleep(5);
    printf("Parent: v is = %d\n", v);
    free(stack);
    return 0;
}

