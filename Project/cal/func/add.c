#include "../calculator.h"
#include <stdio.h>
float add(void){
	int count;
    float sum = 0, num;
    printf("How many numbers do you want to add? ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &num);
        sum += num;
    }
    return sum;
}
