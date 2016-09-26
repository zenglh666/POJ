#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "float.h"

#define count_month 12

int main()
{
	double banlance=0;
	for (int i = 0; i < count_month; i++)
	{
		double x;
		scanf("%lf", &x);
		banlance += x;
	}
	banlance = (banlance/count_month)*100;
	banlance = fmod(banlance, 1) >= 0.5 ? banlance+1 : banlance ;
	banlance = floor(banlance) / 100;
	printf("$%.2f\n", banlance);
	return 0;
}

