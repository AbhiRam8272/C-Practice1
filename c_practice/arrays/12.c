#include<stdio.h>
int main(){
    int a,temp;
    printf("Enter the size of array:");
    scanf("%d",&a);
    int arr[a];
    printf("Enter the elemnts of array:\n");
    for(int i=0;i<a;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<a;i++){
        for(int j=i+1;j<a;j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    } 
    printf("The sorted array in acending order is:\n");
    for(int i=0;i<a;i++)
        printf("%d ",arr[i]);
}        