#include<stdio.h>
int main()
{
int intvar;
float floatvar;
char charvar;
double doublevar;
long double longdoublevar;
printf("size of integer is %zu\n",sizeof(intvar));
printf("size of float is %zu\n",sizeof(floatvar));
printf("size of char is %zu\n",sizeof(charvar));
printf("size of double is %zu\n",sizeof(doublevar));
printf("size of long double %zu\n",sizeof(longdoublevar));
}
