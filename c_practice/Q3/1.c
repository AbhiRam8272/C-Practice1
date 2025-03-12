//CProgram to count digits in a number.
#include<stdio.h>
int main(){
    int a,b=0;
    printf("Enter the number: ");
    scanf("%d",&a);
    for(int i=0;a!=0;i++){
        a/=10;
        b++;
    }
    printf("The integer has %d digits",b);
    return 0;
}