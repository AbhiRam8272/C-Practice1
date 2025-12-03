#include "../calculator.h"   
float divide(void){
	float op1=0,op2=0;
	printf("Enter two numbers: \n");
	scanf("%f %f",&op1,&op2);
	if(op2==0){
		return -1;
	}
	else{
		return op1/op2;
	}
}
