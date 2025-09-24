#include "calculator.h"   
float divide(float op1 , float op2){
	if(op2==0){
		return -1;
	}
	else{
		return op1/op2;
	}
}
