#include<stdio.h>
void lowtoup(char *str){
	int i=0;
	while(str[i]!='\0'){
		if(str[i]>='a' && str[i]<='z')
			str[i]-=32;
		i++;	
	}
}
int main(){
	char str[50];
	printf("Enter a string:");
	scanf("%s",str);
	lowtoup(str);
	printf("string in upper case is %s.\n",str);
}
