//a C program to check whether a given number is even or odd using bitwise operators
#include<stdio.h>
int main(){
    short int a;
    printf("Enter the number:");
    scanf("%hd",&a);
    //printf("%hd\n",a&1);
    if((a&1)==0)
        printf("The number is even\n");
    else
        printf("The number is odd\n");    
}