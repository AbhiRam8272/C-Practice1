#include<stdio.h>
#include<string.h>
int main(){
    char a[20],b[20];
    int c,d,cnt=0,e;
    printf("enter 1st string:");
    fgets(a,sizeof a,stdin);
    printf("enter 2st string:");
    fgets(b,sizeof b,stdin);
    c=strlen(a)-1;
    d=strlen(b)-1;
 printf("%d %d\n",c,d);
    if(c==d){
        for(int i=0;i<c;i++){
            if(a[i]==b[i]){
               cnt++;
              // printf("%d ",cnt);
            }   
        }
        if(cnt==c)
           printf("string are equal\n");
        else
           printf("string are not equal\n"); 
    }
    else 
       printf("string are not equal\n");
    e=strcmp(a,b);
    printf("%d\n",e);
    if(e==0)
      printf("equal");   
}