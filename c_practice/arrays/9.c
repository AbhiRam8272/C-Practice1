#include<stdio.h>
int main(){
    int a,temp,temp1;
    printf("Enter the size of array:");
    scanf("%d",&a);
    int arr[a];
    printf("Enter the elemnts of array:\n");
    for(int i=0;i<a;i++)
        scanf("%d",&arr[i]);
    temp=arr[0];
    temp1=arr[0];
    for(int i=1;i<a;i++){
        if (arr[i]>temp){
            temp=arr[i];
        }
        if (arr[i]<temp1)
            temp1=arr[i];
    }
    printf("the maximum number is %d\n",temp);
    printf("the minimun number is %d\n",temp1);
}