#include<stdio.h>
int main()
{
int a,b;
printf("enter the first number\n");
scanf("%d",&a);

printf("enter the second number\n");                                                                                     scanf("%d",&b);

if (a>b)
        printf("first number is greater %d\n",a);
else if (b>a)
        printf("second number is greater %d\n",b);

else if (a==b)
        printf("both numbers are same%d\t%d\n",a,b);
}
