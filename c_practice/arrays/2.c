#include<stdio.h>
int main(){
    int a;
    printf("Enetr the size of array:");
    scanf("%d",&a);
    int arr[a];
    printf("Enter the elements of array:\n");
    for(int i=0;i<a;i++)
       scanf("%d",&arr[i]);
    printf("The elements in the array in reverse:\n");
    for(int i=a-1;i>=0;i--)
       printf("%d ",arr[i]);   
}