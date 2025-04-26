#include <stdio.h>

int main()
{
    char n;
    printf("enter the number\n");
    scanf("%hhd",&n);
    for(char i=65+n;i>65;i--){
        for(char j=65;j<i;j++){
            printf("%c ",j);
        }
        for(char k=1;k<((65+n)-i)*2;k++){
            printf("  ");
        }
        for(char l=i-1;l>=65;l--){
            if(l==(64+n)){
                continue;
            }
            else{
            printf("%c ",l);
            }
        }
        printf("\n");
    }

    return 0;
}
