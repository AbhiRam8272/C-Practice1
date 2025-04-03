#include<stdio.h>
int main(){
        int size,cnt,x=0,j,i;
        printf("enter the size\n");
        scanf("%d",&size);
        int arr[size];
        printf("enter the array elements\n");
        for(i=0;i<size;i++){
                scanf("%d",&arr[i]);
        }
        for(i=0;i<size;i++){
                cnt=0;
           for(j=0;j<size;j++){
                 if(i!=j){
                        if(arr[i]==arr[j]){
                           cnt++;
                           break;
                 }
           }
           }
                 if(j>i&&cnt>0){
                         x++;
                         //printf("%d %d %d %d\n",i,j,cnt,x);

                 }

           }
           printf("Number of duplicate elements is: %d\n",x);
           return 0;
        }