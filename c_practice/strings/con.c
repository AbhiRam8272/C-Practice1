#include<stdio.h>
#include<string.h>
int main(){
    char a[100],b[20];
    int c;
    printf("enter 1st string:");
    fgets(a,sizeof a,stdin);
    printf("enter 2st string:");
    fgets(b,sizeof b,stdin);
    c=strlen(a)-1;
    for(int i=0;b[i]!=0;i++,c++){
        a[c]=b[i];
    }
    puts(a);
}