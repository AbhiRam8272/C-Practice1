//Factorial Using Pointers
#include<stdio.h>
int fact(int *p){
    int f=1;
    for(int i=1;i<=*p;i++){
        f*=i;
    }
    return f;
}
int main(){
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    printf("The factorial of %d is %d\n",a,fact(&a));
}