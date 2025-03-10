#include<stdio.h>
#include<math.h>    
int main(){
float a,b,c=1.0,x;
printf("Enter the base and power:\n");
scanf("%f %f",&a,&b);
x=fabs(b);
for(int i=1;i<=x;i++){
    c=c*a;
}  
if(b>0){  
    printf("%f to the power of %f is %f\n",a,b,c);
}
else{
    printf("%f to the power of %f is %f\n",a,b,1/c);
}
return 0;
}