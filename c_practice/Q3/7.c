#include<stdio.h>
int main()
{
int i,j,n;
printf("enter no of tables");
scanf("%d",&n);
for(i=1;i<=10;i++)
{

for(j=1;j<=n;j++)
{

printf("%d * %d = %d\t",j,i,i*j);
}
printf("\n");
}
}
