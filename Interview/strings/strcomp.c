#include<stdio.h>
#include"strings.h"
int strcomp(char *str1,char *str2){
	int i=0;
	while(str1[i]!='\0' && str2[i]!='\0'){
		if (str1[i] != str2[i])
			return -1;
		i++;
	}

	return (str1[i]==str2[i]) ? 0:1;
}

int main(){
	char str1[50],str2[50];
	printf("Enter string 1:");
	scanf("%s",str1);
	printf("Enter string 2:");
	scanf("%s",str2);
	if(strcomp(str1,str2)==0)
		printf("Strings are same.\n");
	else
		printf("Strings are not same.\n");
	return 0;
}
