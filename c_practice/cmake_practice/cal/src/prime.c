#include "calculator.h"   
int prime(int num){
	int temp=0;
	if(num<=1){
		return 0;
	}
	else if(num==2){
		return 1;
	}
	else{
		for (int i = 2; i <= num / 2; i++) {
		       	if (num % i == 0) {
				temp++;
				break;
			}	
		}
	}
	if (temp == 0) {
		return 1;
	}
		
	else {
		return 0;
	}
}
