#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    const char *dir = ".";
    if (argc > 1) {
        dir = argv[1];
    }

    DIR *d = opendir(dir);
    if (!d) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        printf("%s  ", entry->d_name);
    }
    printf("\n");

    closedir(d);
    return 0;
}

