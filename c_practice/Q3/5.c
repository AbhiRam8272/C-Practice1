#include<stdio.h>
int main()
{
int i,n;
printf("enter the value till where we should print leap year\n");
scanf("%d",&n);
for(i=1;i<=n;i++){
	if((i%4==0)&&(i%100!=0)|(i%400==0))
			{
				printf("%d\n",i);
			}
}}
