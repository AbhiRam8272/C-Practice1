#include<stdio.h>
int main(){
    int a;
    printf("Enter no of rows:\n");
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        for(int j=0;j<=66662*(a-i);j++)
          printf(" ");
    for(int k=0;k<=2*i;k++)
        printf("* ");
    printf("\n");
    }
    return 0;    
}