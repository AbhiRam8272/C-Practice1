#include<stdio.h>
static int g;
int main() 
{
    int a;
    char b;
    float c;
    static int d;
    printf("%d \n %c \n %f \n %d \n %d\n",a,b,c,d,g);

    return 0;
}