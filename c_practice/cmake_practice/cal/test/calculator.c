#include <stdio.h>
#include "calculator.h"

int main(){
	int num1,num,choice;
	float op1,op2;
start:  printf("Select the operation:\n1:ADDITION\n2:SUBTRCTION\n3:MULTIPLICATION\n4:DIVISION\n");
	printf("5:CHECK IF THE NUMBER IS PRIME OR NOT\n6:FIBONACCI SERIES UPTO A GIVEN NUMBER\n7:CHECK THE NUMBER IS ODD OR EVEN\n");
	printf("Enter the option here:");
	scanf("%d",&choice);
	switch(choice){
		case 1: 
			printf("\n\nADDITION\n");
			printf("%.5f",add());
			break;
		case 2:
			printf("\n\nSUBTRACTION\n");
                        printf("%.5f",sub());
                        break;
		case 3:
			printf("\n\nMULTIPLICATION\n");
			printf("%.5f",mul());
                        break;
		case 4:
			printf("\n\nDIVISION\n");
			printf("Only 2 operands are possible here....\n");
			printf("Enter operand 1:\n");
			scanf("%f",&op1);
			printf("Enter operand 2:\n");
                        scanf("%f",&op2);
                        printf("%.5f",divide(op1,op2));
                        break;
		case 5:
			printf("\n\nCHECK IF THE NUMBER IS PRIME OR NOT\n");
			printf("Enter the number to check for prime:");
			scanf("%d",&num);
			if(prime(num)==0){
				printf("%d is not a prime number.",num);
			}
			else{
				printf("%d is a prime number.",num);
			}
			break;
		case 6:
			printf("\n\nFIBONACCI SERIES UPTO A GIVEN NUMBER\n");
			printf("Enter the number of terms in fibinacci series:");
			scanf("%d",&num);
			printFib(num);
			break;
		case 7:
			printf("\n\nCHECK THE NUMBER IS ODD OR EVEN\n");
			printf("Enter the number to check wheather it's even or odd:");
			scanf("%d",&num);
			int a;
			a=odd_even(num);
			if(a==1){
				printf("%d is a even number.\n\n",num);
			}
			else if(a==0){
				printf("%d is a odd number.\n\n",num);
			}
			else{
				printf("%d is nor even or odd\n\n",num);
			}
			break;
		default:
			printf("Invalid options.\n\n");
			goto start;
	}
	printf("\n\nDo you want to continue with your calculations(1->YES 2->NO):");
        scanf("%d",&num1);
	if(num1==1){
		goto start;
	}
	else{
		printf("THANK YOU :)\n\n");
		return 0;
	}
}

