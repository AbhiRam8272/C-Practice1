#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>
#include <string.h>

void create_daemon()
{
    pid_t pid;

    // Fork off the parent process
    pid = fork();

    if (pid < 0)
        exit(EXIT_FAILURE);

    // If we got a good PID, then exit the parent
    if (pid > 0)
        exit(EXIT_SUCCESS);

    // Child process continues here

    // Create new session and become session leader
    if (setsid() < 0)
        exit(EXIT_FAILURE);

    // Catch, ignore and handle signals (example)
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    // Fork again to ensure the daemon is not a session leader
    pid = fork();
    if (pid < 0)
        exit(EXIT_FAILURE);
    if (pid > 0)
        exit(EXIT_SUCCESS);

    // Set new file permissions
    umask(0);

    // Change working directory to root
    chdir("/");

    // Close all open file descriptors
    for (int x = sysconf(_SC_OPEN_MAX); x>=0; x--)
    {
        close(x);
    }
}

int main()
{
    create_daemon();

    // Open a log file in write mode.
    FILE *fp = fopen("/tmp/daemon.log", "w+");

    if (fp == NULL)
        exit(EXIT_FAILURE);

    while (1)
    {
        time_t now = time(NULL);
        char *time_str = ctime(&now);
        time_str[strlen(time_str)-1] = '\0'; // remove newline

        fprintf(fp, "Daemon still alive at %s\n", time_str);
        fflush(fp);

        sleep(5); // wait 5 seconds
    }

    fclose(fp);
    return 0;
}

