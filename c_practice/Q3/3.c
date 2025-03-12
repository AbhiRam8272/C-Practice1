// CProgram to reverse a number (for example input: 1234, output: 4321).
#include<stdio.h>
int main(){
    int a,b,c=0;
    printf("Enter the number: ");
    scanf("%d",&a);
    for(int i=0;a!=0;i++){
        b=a%10;
        c=c*10+b;
        a/=10;
    }
    printf("The reversed integer is %d\n",c);
    return 0;
}