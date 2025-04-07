#include<stdio.h>
int main()
{
int a,b,c;
printf("enter the values of a,b\n");
scanf("%d%d",&a,&b);
c=a;
a=b;
b=c;
printf("the values after swapping a is %d b is %d",a,b);
}
