#include<stdio.h>
int main(){
    int arr[10]={1,1,2,3,3,4,5,6,5};
    int a;
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        a=arr[i];
        for(int j=i+1;j<(sizeof(arr)/sizeof(arr[0]));j++){
            if(a==arr[j])
              arr[i]=arr[j+1];
        }
    }
    for(int x=0;x<(sizeof(arr)/sizeof(arr[0]));x++)
        printf("%d ",arr[x]);
 return 0;    
}