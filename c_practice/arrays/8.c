#include<stdio.h>
int main(){
    int a,cnt,x=0,j,i,b;
    printf("Enter the size of array:");
    scanf("%d",&a);
    int arr[a];
    printf("Enter the elemnts of array:\n");
    for(int i=0;i<a;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<a;i++){
        cnt=1;
        b=arr[i];
        for(j=0;j<a;j++){
            if(i!=j){
                if(arr[i]==arr[j]){
                    cnt++;
                    break;
                 }
           }
        }
        if(b!=arr[i+1])
           printf("%d occurs %d times\n",arr[i],cnt);
    }
}    