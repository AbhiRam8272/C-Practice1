#include<stdio.h>
int sort();
int main(){
    int a,cnt,x=0,j,i;
    printf("Enter the size of array:");
    scanf("%d",&a);
    int arr[a];
    printf("Enter the elemnts of array:\n");
    for(int i=0;i<a;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<a;i++){
        cnt=0;
        for(j=0;j<a;j++){
            if(i!=j){
                if(arr[i]==arr[j]){
                    cnt++;
                    break;
                 }
           }
        }
        if(cnt==0){
            printf("Unique elements are:\n");
            printf("%d\n",arr[i]);
        }
    }
    //printf("Number of duplicate elements is: %d\n",x);
    return 0;
}