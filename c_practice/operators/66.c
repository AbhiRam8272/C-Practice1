#include<stdio.h>
#include<stdint.h>
int main(){
    uint8_t  a,b;
    int c=0;
   go: printf("Enter a number:");
    scanf("%hhd",&a);
    b=a;
    if(((a&(a-1))!=0)||a==0)
        printf("%d is not a power of 4\n",a);
    else{
        while(a>0){
            if((a&1)==0)
              c++;
           a=a>>1;   
        }
        if ((c%2)==0)
            printf("%d is power of 4\n",b);
        else 
           printf("%d is not power of 4\n",b);    
    }
    goto go;
    return 0;
}