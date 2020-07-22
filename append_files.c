#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main(int argc, char** argv)
{
	if(argc != 3)
	{
		puts("usage: command <file1 to be appended> <file2>");
		return -1;
	}		

	FILE *fp1 = fopen(argv[1], "a+");
	FILE *fp2 = fopen(argv[2], "r");
	
	if(fp1 == NULL)
	{
		puts("open file 1 failed");
		return -2;
	}
	if(fp2 == NULL)
	{
		puts("open file 2 failed");
		return -2;
	}


	if(setvbuf(fp1, NULL, _IOFBF, BUFSIZE) != 0)
	{
		puts("set buf of file1 failed");	
		return -3;
	}
	if(setvbuf(fp2, NULL, _IOFBF, BUFSIZE) != 0)
	{
		puts("set buf of file2 failed");	
		return -3;
	}


	char buff[BUFSIZE];
	int n;
	while((n=fread(buff, 1, BUFSIZE, fp2)) != 0)
		fwrite(buff, 1, n, fp1);
	
	fclose(fp2);
	fclose(fp1);
	return 0;
}
