#include<stdio.h>
int main(){
    int a,b,c,d;
    printf("enter the dimensions of 1st matrix(rows columns):\n");
    scanf("%d%d",&a,&b);
    int x[a][b];
    printf("enter the first matrix:\n");
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            printf("enter a%d%d element:",i+1,j+1);
            scanf("%d",&x[i][j]);
        }
    }
    printf("enter the dimensions of 2st matrix(rows columns):\n");
    scanf("%d%d",&c,&d);
    int y[c][d];
    printf("enter the second matrix:\n");
    for(int i=0;i<c;i++){
        for(int j=0;j<d;j++){
            printf("enter a%d%d element:",i+1,j+1);
            scanf("%d",&y[i][j]);
        }
    }
}