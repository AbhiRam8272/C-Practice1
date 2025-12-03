#include<stdio.h>
#include "../calculator.h"   
float mul(void){
	int count;
    float sum = 1, num;
    printf("How many numbers do you want to multiply? ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &num);
        sum *= num;
    }
    return sum;

}

