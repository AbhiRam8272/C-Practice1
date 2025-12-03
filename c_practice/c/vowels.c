#include<stdio.h>
int main()
{
	char str[100];
	char *ptr;
	int count =0;
	printf("enter string:");
	fgets(str,sizeof(str),stdin);
	ptr = str;
	while(*ptr != '\0')
	{
		char ch = *ptr;
		if(ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u'||ch == 'A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U')
			count++;
		ptr++;
	}
	printf("%d\n",count);
	return 0;
}
