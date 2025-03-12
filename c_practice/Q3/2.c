// CProgram to calculate SUM & PRODUCT of all digits
#include<stdio.h>
int main(){
    int a,sum=0,pro=1;
    printf("Enter the number: \n");
    scanf("%d",&a);
    for(int i=0;a!=0;i++){
        sum+=a%10;
        pro*=a%10;
        a/=10;
    }
    printf("The sum of digits is %d\n",sum);
    printf("The product of digits is %d\n",pro);
}