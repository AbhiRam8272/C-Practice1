//Add Numbers Using Call by Reference
#include<stdio.h>
int add(int *p,int *q ){
    int sum;
    sum=*p+*q;
    return sum;
}
int main(){
    int a=5,b=6;
    printf("%d",add(&a,&b));
}