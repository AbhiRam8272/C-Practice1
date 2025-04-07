#include<stdio.h>
int main()
{
long long int i;

	int count=0;
printf("enter the number\n");
scanf("%lld",&i);
if(i==0)
{
printf("the no of digits in the number is 1");
}
else {
while(i>0){
	i=i/10;
	count++;
}printf("no of digits in the number is%d\n",count);}

}
