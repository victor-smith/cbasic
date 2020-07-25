#include <stdio.h>
#include <string.h>

int str_len(char *str)
{
	int count = 0;
	while(*str++)
		count++;

	return count;
}

int main()
{
	char ch[20];
	char ch1[20];
	//char *ch2=(char*)malloc(20);
	printf("str_len is %d\n",str_len(ch));	
	printf("strlen is %d\n",strlen(ch));	
	printf("ch is %s\n",ch);	

	strcat(ch, "hello world ni shi zuihao de shi ma hello a ");
	printf("ch is %s, len of ch is %d\n",ch, strlen(ch));	

	strncat(ch1, "hello world ni shi zuihao de shi ma hello a ", 20-strlen(ch1)-1);
	printf("ch1 is %s, len of ch is %d\n",ch1, strlen(ch1));	

	//strncat(ch2, "hello world ni shi zuihao de shi ma hello a ", 20-strlen(ch2)-1);
	//printf("ch2 is %s, len of ch is %d\n",ch2, strlen(ch2));	
	return 0;
}
