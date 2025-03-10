/*#include<stdio.h>
int main(){
    int a;
    for(int i=1;i<=10;i++){ 
        printf("%d  ",i);
        a=i;
        for(int j=1;j<=9;j++){
        a=a+10;
        printf("%d  ",a);
        }
       printf("\n"); 
    }
}   */
#include<stdio.h>
int main(){
    int a;
    for(int i=1;i<=10;i++){ 
        for(int j=0;j<10;j++){
        printf("%d  ",(j*10)+i);
        }
       printf("\n"); 
    }
}