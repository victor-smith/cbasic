#include <stdio.h>
#include <math.h>

#define RAD_TO_DEG (180/(4*atan(1)))

int main()
{
	double x, y;
	double l, deg;
	puts("input the x y value and q to quit");
	while(scanf("%lf %lf", &x, &y)==2)
	{
		l = sqrt(x*x+ y*y);
		deg =RAD_TO_DEG* atan2(y,x);
		printf("magnitude:%f, angle %f\n", l, deg);
	}
	return 0;
}
