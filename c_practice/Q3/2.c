#include<stdio.h>
int main(){
	int n,t,sum,product;
	printf("enter the number\n");
	scanf("%d",&n);
	t=0;
	sum=0;
	product=1;
	while(n>0)
{
t=n%10;
sum=sum+t;
product=product*t;
n=n/10;

}

printf("sum is %d and product is %d\n",sum,product);}
