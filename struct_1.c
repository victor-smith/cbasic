#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define LEN 20

typedef struct {
	char firstName[LEN];
	char lastName[LEN];
} SName;

SName  getNameInfo();
void showNameInfo(SName name);
void saveToDb(SName name[], int n, char *filename);
SName* readDb(char *filename);

int main()
{
	#define NUMNAMES 3
	SName names[NUMNAMES];
	int i;
	for(i=0; i<NUMNAMES; i++)
	{
		names[i] = getNameInfo();
	}
	
	for(i=0; i<NUMNAMES; i++)
	{
		showNameInfo(names[i]);
	}
		
	saveToDb(names, NUMNAMES, "name.db");
	readDb("name.db");
	return 0;
}


SName getNameInfo()
{	
	SName sname;
	
	puts("please intput the first name:");
	scanf("%s",sname.firstName);

	
	puts("please intput the last name:");
	scanf("%s",sname.lastName);
	
	return sname;	
}

void showNameInfo(SName sname)
{
	printf("first name is %s\n",sname.firstName);
	printf("last name is %s\n",sname.lastName);
}

void saveToDb(SName name[], int n, char *filename)
{
	assert(name != NULL);
	assert(n>0);
	assert(filename != NULL);
	
	int i;
	FILE *fp = fopen(filename, "wb+");
	if(fp == NULL)
	{
		perror("open file failed");
		exit(-1);
	}
	
	fwrite(name, sizeof(SName), n, fp);

	rewind(fp);
	SName tmp[n];
	fread(tmp, sizeof(SName),n,fp);
	puts("read files");
	showNameInfo(tmp[0]);
	showNameInfo(tmp[1]);
	showNameInfo(tmp[2]);
	
	fclose(fp);
	return;
}

SName* readDb(char *filename)
{
	assert(filename != NULL);
	
	int i;
	FILE *fp = fopen(filename, "r");
	if(fp == NULL)
	{
		perror("open file failed");
		exit(-1);
	}
		
	
	SName *ret;	
	SName sname[3];	
	int count=0;
	fread(sname, sizeof(SName),3, fp);

	for(i=0; i<3; i++)
	{
		puts(sname[i].firstName);
		puts(sname[i].lastName);
	}	
	{
		
/*	
		count++;	
		ret = (SName*)realloc(ret, sizeof(SName)*count);	
		ret[count-1] = sname;
*/
	}	
	fclose(fp);
	return ret;
}
