#include<stdio.h>
int main(){
    int a;
    printf("Enter no of rows:\n");
    scanf("%d",&a);
    for(int i=a-1;i>=0;i--){
        for(int j=0;j<=2*(a-i);j++)
          printf(" ");
    for(int k=0;k<=2*i;k++)
        printf("* ");
    printf("\n");
    }
    return 0;    
}