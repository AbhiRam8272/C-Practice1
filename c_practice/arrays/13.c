#include<stdio.h>
int main(){
    int a,temp;
    printf("Enter the size of array:");
    scanf("%d",&a);
    int arr[50];
    printf("Enter the elemnts of sorted array:\n");
    for(int i=0;i<a;i++)
        scanf("%d",&arr[i]);
    printf("The existing array list is :\n");
    for(int i=0;i<a;i++)
        printf("%d ",arr[i]);    
    printf("\nInput the value to be inserted :\n");
    scanf("%d",&temp);
    for(int i=0;i<a;i++){
        if(temp<arr[i]){
            for(int j=0;j<=a-i;j++)
                arr[a-j]=arr[a-j-1];
            arr[i]=temp;
            break;    
        } 
    }
    a++;
    printf("\nAfter Insert the list is :\n");
    for(int i=0;i<a;i++)
        printf("%d ",arr[i]);    
}        