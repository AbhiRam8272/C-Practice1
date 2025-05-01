#include<stdio.h>
int binary(int a1[],int l1,int r1,int key1){
    int mid;
    mid=(l1+r1)/2;
    //printf("%d %d %d \n",l1,r1,key1);
    if(l1<=r1){
       if(a1[mid]==key1){
        return mid;
       }
       else if(a1[mid]>key1){
        r1=mid-1;
       }
       else if(a1[mid]<key1){
        l1=mid+1;
       }
       binary(a1,l1,r1,key1);
    } 
    else {
        return -1;
    }
}
int main(){
    int n,l=0,r,key,x;
    printf("Enter len of array:");
    scanf("%d",&n);
    int a[n];
    r=n-1;
    printf("Enter the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
num: printf("Enter the number to search:");
    scanf("%d",&key);
    x=binary(a,l,r,key);
    if(x!=-1){
        printf("The given number is present in the array at position %d\n",x);
    }
    else{
        printf("The number is not present in the array.\nPlease enter the number to search\n");
        goto num;
    }
    return 0;
}