#include<stdio.h>
#include"strings.h"
void reverse(char *str){
    char temp;
    int a=0,b=strleng(str)-1;
    while(a<b){
        temp=str[a];
        str[a]=str[b];
        str[b]=temp;
        a++;
        b--;
    }
}
int main(){
    char str[50];
    printf("Enter a string:");
    scanf("%s",str);
    printf("Before reversing:%s.\n",str);
    reverse(str);
    printf("After reversing:%s.\n",str);
    return 0;
}