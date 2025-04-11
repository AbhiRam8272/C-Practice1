// Add Two Numbers with Pointers
#include<stdio.h>
int main(){
    int a=5,b=6,*p,*q;
    p=&a;
    q=&b;
    printf("%d",*p+*q);
}