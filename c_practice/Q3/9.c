#include<stdio.h>
int main()
{
int n,num;
printf("enter the number in binary form for left shift\n");
scanf("%b",&num);
printf("enter how many times u want to left shift\n");
scanf("%d",&n);
        num=(num<<n);
        printf("number after right shift is : %b",num);
}
