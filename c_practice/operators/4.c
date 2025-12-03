//C program to count the number of set bits (1s) in the binary representation of a given integer.
#include<stdio.h>
int main(){
    short int a,b=0,c;
    printf("enter the number:");
    scanf("%hd",&a);
    c=a;
    for(int i=0;c!=0;i++){
        b+=c&1;
        c>>=1;
    }
    printf("The number of set bits in %d are %d\n",a,b);
}