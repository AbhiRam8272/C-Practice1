#include<stdio.h>
void toggle(char *str){
	int i=0;
	while(str[i]!='\0'){
		if(str[i]>='A' && str[i]<='Z')
			str[i]+=32;
		else if(str[i]>='a' && str[i]<='z')
			str[i]-=32;
		i++;	
	}
}
int main(){
	char str[50];
	printf("Enter a string:");
	scanf("%s",str);
	toggle(str);
	printf("string after toggling cases is %s.\n",str);
}
