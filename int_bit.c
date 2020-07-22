#include <stdio.h>
#include <stdlib.h>

void itobs(int num, char bits[]);
void showbs(char bits[], int n);
int main()
{
	int num=0;
	char bs[sizeof(int)*8+1];
	while(scanf("%d", &num))
	{
		itobs(num, bs);
		bs[sizeof(int)*8]='\0';
		//printf("%s\n",bs);
		showbs(bs, sizeof(int)*8);	
	}	

	return 0;
}


void itobs(int num, char bits[])
{
	int i=0; 
	for(i=0; i<sizeof(int)*8; i++)
	{
		bits[sizeof(int)*8-i-1] = (num&1)+'0';
		num>>=1;
	}
}


void showbs(char bits[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%c",bits[i]);
		if( (1+i)%4==0)
			printf(" ");
	}
	printf("\n");
}
