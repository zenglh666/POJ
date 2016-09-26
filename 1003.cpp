#include "stdlib.h"
#include "stdio.h"

#define max_n 280

int interval_search(float x, float *directory, int i, int j)
{
	while (i <= j)
	{
		int mid = (i + j) / 2;
		if (directory[mid] > x)
		{
			j = mid - 1;
		}
		else if (directory[mid] < x)
		{
			i = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return i;
}

int main()
{
	float directory[max_n];
	directory[0] = 0;
	for (int i = 1; i < max_n; i++)
	{
		directory[i] = 1 / float(i + 1)+directory[i-1];
	}
	float x;
	while (scanf("%f", &x)==1)
	{
		if (x == 0.0)
		{
			break;
		}
		else
		{
			int n = interval_search(x, directory, 0, max_n - 1);
			printf("%d card(s)\n", n);
		}
	}
	return 0;
}

