// C program to check whether a given number is a power of two or not, using bitwise operators
#include<stdio.h>
int main(){
    short int a,b=0,c;
    printf("enter th number:");
    scanf("%hd",&a);
   // printf("%b",a);
    c=a;
    for(int i=0;c!=0;i++){
        b+=c&1;
        c>>=1;
    }
    if(b==1)
    printf("%d is power of 2",a);
    else
    printf("%d is not power of 2",a);
}