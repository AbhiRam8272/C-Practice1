#include <stdio.h>
int main()
{
    char n;
    char tem;
    printf("enter the number\n");
    scanf("%hhd",&n);
    tem=n;
    char g;
    for(char i=97;i<97+n;i++){
        tem=i-97;
        g=1;
        for(char k=97+(n-1);k>i;k--){
            printf("  ");
        }
        for(char j=i-(i-1);j<(i-96)*2;j++){
            if(j<=i-96){
            printf("%c ",i-tem);
            tem--;
            }
            else{
                printf("%c ",i-g);
                g++;
            }
        }
        
        printf("\n");
    }

}