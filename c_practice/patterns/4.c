#include <stdio.h>

int main()
{ int n;
    printf("enter the number\n");
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        for(int j=n;j>i;j--){
            printf(" ");
        }
        for(int k=1;k<i*2;k++){
            if((k==1)||k==(i*2)-1)
                printf("*");
            else
            printf(" ");
               }
     printf("\n");
    }
    for(int i=1;i<n*2;i++){
        printf("*");
    }

    return 0;
}