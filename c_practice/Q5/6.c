#include<stdio.h>
int main()
{                                                                                                                                    int a,b;
	float c;
printf("enter the values of a,b\n");
scanf("%d%d",&a,&b);
c=a/b;
printf("value of c before typecastingis %f\n",c);
c=a/(float)b;
printf("value of c after typecasting is :%f\n",c);
}     
