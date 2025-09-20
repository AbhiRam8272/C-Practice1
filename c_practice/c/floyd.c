#include<stdio.h>
int main()
{
	int n,l=1;
	printf("rows\n");
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
		for(int k=1;k<=n-i;k++)
		{
			printf("  ");
		}
		for( int j=1;j<=i;j++)
		{
			printf("%4d",l);
			l++;
		}
		printf("\n");
		
	}
}
