//Maximum of Two Using Pointer
#include<stdio.h>
int main(){
    int a=5,b=6,*p,*q;
    p=&a;
    q=&b;
    if(*p>*q)
       printf("%d is greater",*p);
    else 
       printf("%d is greater",*q);
}