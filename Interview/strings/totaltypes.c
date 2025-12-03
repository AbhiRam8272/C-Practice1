#include<stdio.h>
void total(char *str){
	int i=0,a=0,d=0,s=0;
	while(str[i]!='\0'){
		if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
			a++;
		else if(str[i]>='0' && str[i]<='9')
			d++;
		else
			s++;

		i++;	
	}
	printf("total no.of alphabets:%d,digits:%d,special characters:%d.\n",a,d,s);
}
int main(){
	char str[50];
	printf("Enter a string:");
	scanf("%s",str);
	total(str);
}
