#include<stdio.h>
int main(){
    int a;
    printf("Enetr the size of array:");
    scanf("%d",&a);
    int arr1[a],arr2[a];
    printf("Enter the elements of array:\n");
    for(int i=0;i<a;i++)
       scanf("%d",&arr1[i]);
    for(int i=0;i<a;i++)
         arr2[i]=arr1[i];
    printf("The elements of 1st array are:\n");      
    for(int i=0;i<a;i++)
         printf("%d ",arr1[i]);
    printf("\nThe elements of 2nd array are:\n");     
    for(int i=0;i<a;i++)
         printf("%d ",arr2[i]);               
}