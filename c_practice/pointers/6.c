//String Length Using Pointer
#include<stdio.h>
int main(){
    char a[30];
    int b=0;
    printf("Enter a string:");
    fgets(a,30,stdin);
    for(int i=0;*(a+i)!='\0';i++){
       b++;
    }
    printf("%d",b-1);
}