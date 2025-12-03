#include<stdio.h>
int main()
{
	int n;
float f,c;
printf("do u want to convert fahrenheit to celsius(1) or celsius to fahrenheit(2)\n");
printf("enter 1 for fahrenheit to celsius and enter 0 for celsius to fahrenheit \n");
scanf("%d",&n);
if(n==1)
{
printf("enter the fahrenheit temp\n");
scanf("%f",&f);
c=(f-32)*5/9;
printf("the value in celsius is %.f\n",c);
}
else if(n==0) {
printf("enter the celsius temp\n");
scanf("%f",&c);
f=(c*9/5)+32;
printf("the value in fahrenheit is %f\n",f);
}
}
