#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

void print_file_info(const char *path, const char *name) {
    struct stat st;
    char full_path[1024];

    snprintf(full_path, sizeof(full_path), "%s/%s", path, name);

    if (stat(full_path, &st) == -1) {
        perror("stat");
        return;
    }

    if (S_ISDIR(st.st_mode)) {
        printf("%s/\t", name);  // Directory
    } else if (S_ISLNK(st.st_mode)) {
        printf("%s@\t", name);  // Symlink
    } else if (st.st_mode & S_IXUSR) {
        printf("%s*\t", name);  // Executable
    } else {
        printf("%s\t", name);   // Regular file
    }
}

int main(int argc, char *argv[]) {
    const char *dir = ".";
    int show_hidden = 0;

    // Check for options like -a
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            show_hidden = 1;
        } else {
            dir = argv[i];
        }
    }

    DIR *d = opendir(dir);
    if (!d) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        if (!show_hidden && entry->d_name[0] == '.')
            continue;
        print_file_info(dir, entry->d_name);
    }
    printf("\n");

    closedir(d);
    return 0;
}

