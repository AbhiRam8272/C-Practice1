#include<stdio.h>
extern int m;
int fun(int a){
    static int i=50;
    printf(" hi ");
    printf("%d\n",m);
    i=a*i;
    printf("%d\n",i);
}