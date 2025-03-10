#include<stdio.h>
int main(){
    int a,b;
    b=1;
    printf("enter the number to the factorial:\n");
    scanf("%d",&a);
    for(int i=1;i<=a;i++)
       b=b*i;
    printf("The factorial of %d is %d\n",a,b);
    return 0;   
}