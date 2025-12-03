#include<stdio.h>
#include"strings.h"
int strleng(char *str1){
	int len=0,i=0;
	while(*str1++){
		len++;
	}
	return len;
}

void strcopy(char *str1,char *str2){
	while(*str1!='\0'){
		*str2=*str1;
		str1++;
		str2++;
		}
	*str2='\0';
}

void strconc(char *str1,char *str2){
	int len=strleng(str1);
	while(*str2!='\0'){
		str1[len]=*str2;
		len++;
		str2++;
		}
	str1[len]='\0';
}

