#include<stdio.h>
int main()
{
	int n,d,r;
	r=0;
printf("enter the number to reverse\n");
scanf("%d",&n);
while(n>0)
{
d=n%10;
r=(r*10)+d;
n=n/10;
}
printf("number after reversing is %d\n",r);
}
