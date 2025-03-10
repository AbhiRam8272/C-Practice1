void pb(unsigned int num) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0 && i != 0) {
            printf(" "); // Add space for readability
        }
    }
    printf("\n");
} 