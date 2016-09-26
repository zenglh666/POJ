#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define erode_per_year 50.0
#define pi 3.1415926

typedef struct cord
{
	float x, y;
}cord;


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cord c;
		scanf("%f %f", &c.x, &c.y);
		float r = sqrt(pow(c.x, 2) + pow(c.y, 2));
		float area = (r*r*pi) * 0.5;
		int year = int(ceil(area / erode_per_year));
		printf("Property %d: This property will begin eroding in year %d.\n", i + 1, year);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}

