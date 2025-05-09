#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,*p,temp,i,b;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    b=n;
    p=(int *)malloc(n*sizeof(int));
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",p+i);
    }
     for(i=0;i<n;i++)
    {
        printf("%d ",*(p+i));
    }
    if(n%2!=0)
    {
        b=n-1;
    }
    for(i=0;i<b;i+=2)
    {
        temp=*(p+i);
        *(p+i)=*(p+(i+1));
        *(p+(i+1))=temp;
    }
    printf("\n");
    printf("Elements after swapping:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(p+i));
    }
    if(p!=NULL)
    {
        free(p);
    }
    return 0;
}