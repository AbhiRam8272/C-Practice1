#include<stdio.h>
#include<string.h>
int main(){
    char str[20],temp;
    int a;
    printf("enter a string:");
    fgets(str,sizeof str,stdin);
    printf("entered string is %s",str);
    a=strlen(str)-1;
    printf("%d\n",a);
       for(int i=0;i<a/2;i++){
           temp=str[a-i-1];
           str[a-i-1]=str[i];
           str[i]=temp;
            //printf("%s",str);
        }
   printf("%s",str);
}