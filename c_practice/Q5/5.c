#include<stdio.h>
int main()
{
int a,b;
printf("swapping without using 3rd var and using arthematic operations\n");
printf("enter the values of a,b\n");
scanf("%d%d",&a,&b);
a=a+b;
b=a-b;
a=a-b;
printf("values after swapping a is %d b is %d",a,b);
}
