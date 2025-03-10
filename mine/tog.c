#include<stdio.h>
#include "binary.h"
int main(){
    int a=5;
    a=a^((1<<1) | (1<<2));
    pb(a);
    printf("%d\n",a);

}