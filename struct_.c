#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//#pragma pack(push)
//#pragma pack(1)
struct  book1{
	float value1;	
	char *title;
	char *name;
	float value2;	
	char tmp1;
} book1;

struct book2{
	char title[5];
	char name[5];
	float value;	
} book2;

struct book3{
	float value;	
	//char title[];
	char name[];
} book3;


typedef struct {
	char *firstName;
	char *lastName;
} SName;

SName * getNameInfo();
void showNameInfo(SName* name);
void saveToDb(SName *name[], int n, char *filename);

int main()
{
	/*
	printf("sizeof info: book1 %d, book2 %d, book3 %d\n",
		 sizeof(struct book1), sizeof(struct book2), sizeof(struct book3));
	printf("sizeof(char*)%d, sizeof(char[5]) %d. sizeof(float) %d\n",
		sizeof(char*), sizeof(char[5]), sizeof(float));
	*/
	#define NUMNAMES 3
	SName *names[NUMNAMES];
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
	return 0;
}


SName *getNameInfo()
{	
	SName *sname = (SName*)malloc(sizeof(SName));
	char name[80];
	
	puts("please intput the first name:");
	while(scanf("%s",name)==0) continue;
	sname->firstName = (char*)malloc(strlen(name)+1);
	strncpy(sname->firstName, name, strlen(name)+1);

	
	puts("please intput the last name:");
	while(0==scanf("%s",name))continue;
	sname->lastName= (char*)malloc(strlen(name)+1);
	strncpy(sname->lastName, name, strlen(name)+1);
	
	return sname;	
}

void showNameInfo(SName *sname)
{
	printf("first name is %s\n",sname->firstName);
	printf("last name is %s\n",sname->lastName);
}

void saveToDb(SName *name[], int n, char *filename)
{
	assert(name != NULL);
	assert(n>0);
	assert(filename != NULL);
	
	#define BUFFSIZE 4096
	int i;
	char buff[BUFFSIZE];
	FILE *fp = fopen(filename, "a+");
	if(fp == NULL)
	{
		perror("open file failed");
		exit(-1);
	}
		
	if(setvbuf(fp, NULL, _IOFBF, BUFFSIZE) != 0)
	{
		perror("set buffer size failed");
		exit(-2);
	}
	
	for(i=0; i<n; i++)
	{
		fwrite(name[i]->firstName, sizeof(name[i]->firstName)+1, 1, fp);
		fwrite(name[i]->lastName, sizeof(name[i]->lastName)+1, 1, fp);
	}
	
	fclose(fp);
	return;
}
//#pragma pack(pop)
