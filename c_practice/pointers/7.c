//Swap Elements Using Call by Reference
#include<stdio.h>
int swap(int *p,int *q){
    *p^=*q;
    *q^=*p;
    *p^=*q;
}
int main(){
    int a,b;
    printf("enter 2 numbers:");
    scanf("%d%d",&a,&b);
    printf("numbers before swapping are a=%d,b=%d\n",a,b);
    swap(&a,&b);
    printf("numbers before swapping are a=%d,b=%d",a,b);
}