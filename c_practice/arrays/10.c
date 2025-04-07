#include<stdio.h>
int main(){
    int a;
    printf("Enter the size of array:");
    scanf("%d",&a);
    int arr[a];
    printf("Enter the elemnts of array:\n");
    for(int i=0;i<a;i++)
        scanf("%d",&arr[i]);
    printf("the even numbers are:");
    for(int i=0;i<a;i++)
        if(arr[i]%2==0)
           printf("%d ",arr[i]);
    printf("\nthe odd numbers are:");
    for(int i=0;i<a;i++)
        if(arr[i]%2!=0)
           printf("%d ",arr[i]);   
}        