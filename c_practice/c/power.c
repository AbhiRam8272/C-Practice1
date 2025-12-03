#include<stdio.h>
int main()
{
	int n,count =0;
	printf("number\n");
	scanf("%d",&n);
	while(n>0)
	{
		if(n&1==1)
			count++;
		n=n>>1;
	}
	if(count == 1)
	{
		printf("power of 2\n");
	}else
		printf("not power of 2\n");
       return 0;	

}

