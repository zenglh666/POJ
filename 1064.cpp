#include "stdio.h"

#define max_cable_num 10000

int cable[max_cable_num];

int main()
{
	int k, n;
	scanf("%d %d", &n, &k);
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		double c;
		scanf("%lf", &c);
		cable[i] = (int)((c+0.005) * 100);
		if (cable[i] > max)
		{
			max = cable[i];
		}
	}
	int min = 1;
	int len = 0;
	while (max >= min)
	{
		int middle = (max + min) / 2;
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			count += cable[i] / middle;
		}
		if (count >= k)
		{
			min = middle+1;
			len = middle;
		}
		else
		{
			max = middle-1;
		}
	}
	printf("%.2lf\n", ((double)len) / 100.0);
	return 0;
}

