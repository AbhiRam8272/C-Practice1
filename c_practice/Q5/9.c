#include<stdio.h>
int main()
{
	int c,i,b,a;
//	printf("enter the value\n");
//	scanf("%d",&i);
	i=10;
	printf("original value of i is %d\n",i);
	a=++i;
	 printf("value of i after pre increment is %d\n",a);
	b=i++;
	c=i;
	
	printf("value of i after post increment is %d\n",b);
printf(" value of c is %d\n",c);
}
