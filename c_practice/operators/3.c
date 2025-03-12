//C program to perform bitwise AND, OR, XOR, operations on two given numbers
#include<stdio.h>
int main(){
    short int a,b;
    printf("Enter 2 numbers:");
    scanf("%hd%hd",&a,&b);
    printf("The bitwise AND for %d and %d is %d\n",a,b,a&b);
    printf("The bitwise OR for %d and %d is %d\n",a,b,a|b);
    printf("The bitwise XOR for %d and %d is %d\n",a,b,a^b);
}