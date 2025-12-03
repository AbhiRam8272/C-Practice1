#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    if(a>0)
      printf("The the given number is positive\n");
    else if(a<0)
      printf("The the given number is negative\n");
    else if(a==0)
      printf("The the given number is zero\n");
    return 0;
}