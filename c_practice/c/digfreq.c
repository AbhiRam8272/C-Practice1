#include<stdio.h>
#include<string.h>
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char str[1000];
    fgets(str,1000,stdin);
    //str[strcspn(str,"\n")]='\0';
    int a[10]={0};
    for(int j=0;str[j]!='\0';j++){
       // printf("%c ",str[j]);
        if(str[j]>=48 && str[j]<=57){
            // printf("%c ",str[j]);
            switch(str[j]){
                case '0': a[0]++;
                        break;
                case '1': a[1]++;
                        break;
                case '2': a[2]++;
                        break;
                case '3': a[3]++;
                        break;
                case '4': a[4]++;
                        break;
                case '5': a[5]++;
                        break;
                case '6': a[6]++;
                        break;
                case '7': a[7]++;
                        break;
                case '8': a[8]++;
                        break;
                case '9': a[9]++;
                        break;
            }                                                  
            }
        }
        for(int i=0;i<10;i++){
            printf("%d ",a[i]);
        }

    
    
    
    return 0;
}