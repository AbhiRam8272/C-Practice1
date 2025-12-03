#include<stdio.h>
#include"strings.h"
void strconc(char *str1,char *str2){
	int len=strleng(str1);
	while(*str2!='\0'){
		str1[len]=*str2;
		len++;
		str2++;
		}
	str1[len]='\0';
}

int main(){
	char str1[50],str2[50];
	printf("Enter string 1:");
	scanf("%s",str1);
	printf("Enter string 2:");
	scanf("%s",str2);
	printf("Before concatination str1=%s,str2=%s.\n",str1,str2);
	strconc(str1,str2);
	printf("After concatination str1=%s,str2=%s.\n",str1,str2);
	return 0;
}
