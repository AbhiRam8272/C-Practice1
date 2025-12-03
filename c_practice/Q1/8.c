#include<stdio.h>
#include<math.h>
int main(){

int p,x,n;
printf("we are doing x^n\n");
printf("enter the values of base and exponent\n");
scanf("%d%d",&x,&n);
p=pow(x,n);
printf("the value of x^n is :%d\n",p);
}
