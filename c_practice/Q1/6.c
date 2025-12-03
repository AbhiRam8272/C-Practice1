#include<stdio.h>
int main()
{
int gross,basic,HRA,other;
printf("enter the basic salary,HRA,other allowances");
scanf("%d%d%d",&basic,&HRA,&other);
gross=basic+HRA+other;
printf("gross salary is :%d",gross);

}
