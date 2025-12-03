#include<stdio.h>
/*short int a=0;
int main(){
a= a|(1<<15);
printf("%d",a);
}*/
int main(){
    int a=0x1234;
    a=((a & 0xFF00) >>8)|((a & 0x00FF) <<8);
    printf("%X",a);
}
