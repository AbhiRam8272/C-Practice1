#include<stdio.h>
int main(){
    int n;
    printf("enter the number\n");
    scanf("%d",&n);
    int m,k=0,l=(n*2)-2,s=(n*2)-2;
    for(int i=0;i<n;i++){
        m=i-1;
        for(int j=0;j<=(n*2)-2;j++){
            if((j<=i)||j>=(s-i)){
                k=i,l=s-i;
                if((k==j)||(l==j)){
                printf("%d ",n-k);
                }
                else if(j<n){
                    printf("%d ",n-j);
                }
                else{
                    printf("%d ",n-m);
                    m--;
                }}
                else{
                    printf("%d ",n-i);
                }
    }
    printf("\n");
    }
    for(int i=n-2;i>=0;i--){
        m=i-1;
        for(int j=0;j<=(n*2)-2;j++){
            if((j<=i)||j>=(s-i)){
                k=i,l=s-i;
                if((k==j)||(l==j)){
                printf("%d ",n-k);
                }
                else if(j<n){
                    printf("%d ",n-j);
                }
                else{
                    printf("%d ",n-m);
                    m--;
                }}
                else{
                    printf("%d ",n-i);
                }
    }
    printf("\n");
    }
    return 0;
}