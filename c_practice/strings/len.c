#include<stdio.h>
#include<string.h>
int main(){
    char a[20];
    int i=0,cnt=0;
    printf("enter the string:\n");
    fgets(a,sizeof a,stdin);
    while(a[i]!='\0'){
        cnt++;
        i++;
    }
    printf("%d",cnt);
    printf("\n%ld",strlen(a));
}