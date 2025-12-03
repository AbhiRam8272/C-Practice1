//Print Array Using Pointer
#include<stdio.h>
int main(){
    int a,*p;
    printf("enter the size of array:");
    scanf("%d",&a);
    int arr[a];
    printf("enter the array:\n");
    for(int i=0;i<a;i++){
        scanf("%d",arr+i);
    }
    printf("entered array is:\n");
    for(int i=0;i<a;i++){
        printf("%d ",*(arr+i));
    }
    return 0;
}