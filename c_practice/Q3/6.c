#include<stdio.h>
int main()
{
int f,n,num;
f=1;
printf("for which number u want to find factorial");
scanf("%d",&n);
num=n;
while(n>0)
{
f=n*f;
n--;
}

printf("the factorial of the number %d is %d",num,f);
}
