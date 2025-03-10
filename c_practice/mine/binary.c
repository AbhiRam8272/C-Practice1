#include<stdio.h>

int main() {
    unsigned int num;
    scanf("%d",&num);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0 && i != 0) {
            printf(" "); // Add space for readability
        }
    }
    printf("\n");
}  