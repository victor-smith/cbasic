#include <stdio.h>
#include <string.h>


struct SProduct1{
	unsigned int color:2;
	unsigned int edge:1;
	unsigned int     :0;
	unsigned int circle:2;
};

struct SProduct2{
	unsigned int color:2;
	unsigned int edge:1;
	unsigned int     :2;
	unsigned int circle:2;
};


int main()
{
	printf("sizeof product1 is %d\n", sizeof(struct SProduct1));
	printf("sizeof product2 is %d\n", sizeof(struct SProduct2));

	struct SProduct1 sp1=(struct SProduct1){3,0,0,3};
	struct SProduct2 sp2=(struct SProduct2){3,0,0,3};

	struct SProduct1 sp3=(struct SProduct1){.color=3,.edge=0,.circle=3};
	
	printf("sp1 info: %d %d %d\n", sp1.color, sp1.edge, sp1.circle);
	printf("sp2 info: %d %d %d\n", sp2.color, sp1.edge, sp2.circle);
	printf("sp3 info: %d %d %d\n", sp3.color, sp3.edge, sp3.circle);
	return 0;
}
