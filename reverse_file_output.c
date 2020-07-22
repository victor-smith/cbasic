#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    	if(argc != 2)
	{
		puts("usage: command <text file name>");
		return -1;
	}	

	FILE *fp = fopen(argv[1], "r+");
	int bytes = 0;
	if(fp == NULL)
	{
		puts("open file failed");
		return -2;
	}
	
	fseek(fp, 0, SEEK_END);
	long last = ftell(fp);
	char ch;
	for(bytes = last-1; bytes >=0; bytes--)
	{
		fseek(fp, bytes, SEEK_SET);
		ch =getc(fp);
		if(ch != '\r')
			putchar(ch);	
	}
	
	fclose(fp);
	puts("");	
	return 0;
}
