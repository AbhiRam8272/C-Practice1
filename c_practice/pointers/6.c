//String Length Using Pointer
#include<stdio.h>
#include<string.h>
int main(){
    char name[50];
    char *p;
    int a,cnt=0;
    printf("Enter a string:");
    fgets(name,50,stdin);
    p=name;
    for(int i=0;*(p+i)!='\0';i++){
        cnt++;
    }
    printf("Length of string is %d\n",cnt-1);
    printf("Length of string is %ld\n",strlen(name)-1);    
}