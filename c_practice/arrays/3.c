#include<stdio.h>
int main(){
    int a,sum=0;
    printf("Enetr the size of array:");
    scanf("%d",&a);
    int arr[a];
    printf("Enter the elements of array:\n");
    for(int i=0;i<a;i++){
       scanf("%d",&arr[i]);
    }
    for(int i=0;i<a;i++){
         sum+=arr[i]; 
    } 
    printf("The sum of elements in the array is:%d\n",sum);    
}