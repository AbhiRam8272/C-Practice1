#include <stdio.h>

int main() {
    int k = 0;
    int n;
    printf("Enter the n value:\n");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            printf("* ");
        }
        for(int k=0;k<2*i;k++){
        printf("  ");
        }
        for(int l=n-i;l>0;l--){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}