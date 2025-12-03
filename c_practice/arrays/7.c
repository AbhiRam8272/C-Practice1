#include<stdio.h>
int sort(int arr[],int size){
        int i,j,temp;
         for(i=0;i<size;i++){
           for(j=i+1;j<size;j++){
                 if(arr[i]>arr[j]){
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                  }
           }
        }
       return arr[size];
}
int main(){
    int m,n,j=0,i;
    printf("Enter the 1 st array size:");
    scanf("%d",&m);
    int arr1[m];
    printf("Enter the 1st array elements:\n");
    for(i=0;i<m;i++)
        scanf("%d",&arr1[i]);
    printf("enter the 2nd array size:");
    scanf("%d",&n);
    int arr2[n];
    printf("enter the 2nd array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&arr2[i]);
    arr1[m]=sort(arr1,m);
    arr2[n]=sort(arr2,n);
    int arr3[m+n];
    for(i=0;i<m+n;i++){
        if(i<m)
            arr3[i]=arr1[i];
        else{
            arr3[i]=arr2[j];
            j++;
        }
    }
    arr3[m+n]=sort(arr3,m+n);
    for(i=0;i<m+n;i++)
        printf("%d ",arr3[i]);
    printf("\n");
    return 0;
}