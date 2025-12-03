#include "calculator.h"   
#include<stdio.h>
float sub(){
	int count;
    float sum , num;
    printf("How many numbers do you want to subtract? ");
    scanf("%d", &count);
    for (int i = count; i >0; i--) {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &num);
        if(i==count){
		sum=num;
	}
	else{
		sum-=num;
	}
    }
    return sum;
}
