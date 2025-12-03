#include<stdio.h>
void strcopy(char *str1,char *str2){
	while(*str1!='\0'){
		*str2=*str1;
		str1++;
		str2++;
		}
	*str2='\0';
}

int main(){
	char str1[50],str2[50];
	printf("Enter string:");
	scanf("%s",str1);
	printf("Before coping str1=%s,str2=%s.\n",str1,str2);
	strcopy(str1,str2);
	printf("After coping str1=%s,str2=%s.\n",str1,str2);
	return 0;
}
