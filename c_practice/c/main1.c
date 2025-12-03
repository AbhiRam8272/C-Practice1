#include<stdio.h>
int m=10;
void fun();
int main(){
    int a=10;
    for(int i;i<=5;i++){
        fun(a);
    }
}


extern int m;
int fun(int a){
    static int i=50;
    printf(" hi ");
    printf("%d\n",m);
    i=a*i;
    printf("%d\n",i);
}