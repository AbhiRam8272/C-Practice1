//Cprogram to print all upper case and lower case alphabets
#include<stdio.h>
#include<string.h>
/*int main(){
    char a[50];
    printf("Enter a string:");
    fgets(a,sizeof(a),stdin);
    printf("Entered string is %s\n",a);
    for(int i=0;i<strlen(a);i++){
        if(a[i]>65 && a[i]<90)
            a[i]+=32;
        else if(a[i]>97 && a[i]<122)
            a[i]-=32;    
    }
    printf("")
}*/
int main(){
    char a[100];
    printf("Enter a string:");
    fgets(a,sizeof(a),stdin);
    printf("Entered string is %s\n",a);
    for(int i=0;i<strlen(a);i++){
        //printf("%d\n",i);
        if(a[i]>=65 && a[i]<=90)
             printf("%c",a[i]);
    }
    printf("\n");      
    for(int i=0;i<sizeof(a);i++){
       // printf("%d\n",i);
        if(a[i]>=97 && a[i]<=122)
             printf("%c",a[i]);
    }   
    printf("\n");
}