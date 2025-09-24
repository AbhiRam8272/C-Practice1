#include "calculator.h"   
int odd_even(int num){

	if(num==0){
		return -1;
	}
	else if(num%2==0){
		return 1;
	}
	else{
		return 0;
	}
}


