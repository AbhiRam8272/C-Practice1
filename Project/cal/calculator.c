#include<stdio.h>
#include "calculator.h"

int main(){
	int choice;

	float (*operations[])(void)={add,sub,mul,divide};
	char*name[]={"Addition","Subtraction","Multiplication","Division"};

	while(1){
		printf("\n=== CALCULATOR MEMU ===\n");
		for(int i=0;i<4;i++){
			printf("%d. %s\n",i+1,name[i]);
		}
		printf("5.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
		if (choice==5){
			printf("Thank You \n Goodbye :)\n");
			break;
		}
		if(choice<1 || choice >5){
			printf("Invalid choice\n");
			continue;
		}

		float res=operations[choice-1]();
		printf("Result = %f\n",res);
	}
}
	
