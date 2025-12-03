#include<stdio.h>
#include"strings.h"

int vowels(char *str){
	int i=0,v=0;
	while(str[i]!='\0'){
		if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
 			v++;
		i++;
	}
	return v;	
}

int main(){
	char str[50];
	int v;
	printf("Enter a string:");
	scanf("%s",str);
	v=vowels(str);
	printf("No.of vowels in '%s' are %d and consonents are %d.\n",str,v,strleng(str)-v);
	return 0;
}
