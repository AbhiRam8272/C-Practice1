#include<stdio.h>
void uptolow(char *str){
	int i=0;
	while(str[i]!='\0'){
		if(str[i]>='A' && str[i]<='Z')
			str[i]+=32;
		i++;	
	}
}
int main(){
	char str[50];
	printf("Enter a string:");
	scanf("%s",str);
	uptolow(str);
	printf("string in lower case is %s.\n",str);
}
