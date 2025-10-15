#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &fileStat) < 0) {
        perror("stat");
        return 1;
    }

    printf("File: %s\n", argv[1]);
    printf("Inode Number: %lu\n", fileStat.st_ino);
    printf("File Size: %ld bytes\n", fileStat.st_size);
    printf("Number of Links: %ld\n", fileStat.st_nlink);
    printf("User ID (Owner): %d\n", fileStat.st_uid);
    printf("Group ID: %d\n", fileStat.st_gid);
    printf("Block Size: %ld\n", fileStat.st_blksize);
    printf("Number of Blocks: %ld\n", fileStat.st_blocks);
    printf("Last Access Time: %ld\n", fileStat.st_atime);
    printf("Last Modification Time: %ld\n", fileStat.st_mtime);
    printf("Last Status Change Time: %ld\n", fileStat.st_ctime);

    printf("File Type: ");
    if (S_ISREG(fileStat.st_mode))  printf("Regular File\n");
    else if (S_ISDIR(fileStat.st_mode)) printf("Directory\n");
    else if (S_ISLNK(fileStat.st_mode)) printf("Symbolic Link\n");
    else if (S_ISCHR(fileStat.st_mode)) printf("Character Device\n");
    else if (S_ISBLK(fileStat.st_mode)) printf("Block Device\n");
    else if (S_ISFIFO(fileStat.st_mode)) printf("FIFO / Pipe\n");
    else if (S_ISSOCK(fileStat.st_mode)) printf("Socket\n");
    else printf("Unknown\n");

    return 0;
}

