//Largest Element Using Dynamic Memory Allocation
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p,n,a,b;
    printf("Input total number of elements(1 to 100):");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    printf("enter %d elements:",n);
    for(int i=0;i<n;i++){
        scanf("%d",(p+i));
    }
    a=*(p+0);
    for(int i=0;i<n;i++){
        printf("%d\n",a);
        if(a<*(p+i)){
           a=*(p+i); 
            
        }    
    }    
    printf("The Largest element is : %d\n",a);
    free(p);
    return 0;
}