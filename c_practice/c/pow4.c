#include<stdio.h>
int main()
{
    int n;
    int ori;
    int pow4=0;
    printf("enter number:");
    scanf("%d",&n);
    ori = n;
    if(n>0)
    {
        while(n%4==0)
        {
            n/=4;
        }
        if(n==1)
        {
            pow4 = 1;
        }
    }
    if(pow4)
    {
        printf("power 0f 4\n");
    }else
    printf("not power of 4\n");
    return 0;
}
