// C program to swap two numbers without using a temporary variable
#include<stdio.h>
int main(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    printf("Two number before swapping are a=%d,b=%d\n",a,b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("Two numbers after swapping are a=%d,b=%d\n",a,b);
}