#include <stdio.h>
#include <stdlib.h>

#define NUM 10000

int main()
{
	char *fileName = "info.dat";
	double data[NUM], value;
	int i;
	FILE *fp;

	for(i=0; i<NUM; i++)
	{
		data[i] = i%1000;
	}
	if((fp = fopen(fileName,"wb"))==NULL)
	{
		puts("open file failed");
		return -1;
	}
	
	fwrite(data, sizeof(double), NUM, fp);
	fclose(fp);

	
	if((fp = fopen(fileName,"rb"))==NULL)
	{
		puts("open file failed");
		return -1;
	}
	
	puts("input the number of data:");
	while(scanf("%d", &i) == 1)
	{
		printf("--> get the value is %d\n", i);
		if( i>=0 && i<NUM)
		{
			fseek(fp, i*sizeof(double), SEEK_SET);
			fread(&value, sizeof(double), 1, fp);
			printf("get the value is %f\n", value);
		}

	}
	fclose(fp);
	return 0;
	
}
	
