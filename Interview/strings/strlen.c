#include<stdio.h>

int strleng(char *str1){
	int len=0,i=0;
	while(*str1++){
		len++;
	}
	return len;
}

int main(){
	char str1[50];
	printf("Enter string:");
	scanf("%s",str1);
	printf("Length of string is %d.\n",strleng(str1));
	return 0;
}
	
