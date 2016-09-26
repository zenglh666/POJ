#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define max_n 26
#define max_h 17

int fi[max_n], ti[max_n], di[max_n];
int fish[max_n];
int ti_sum[max_n];

int find_max_id(int n)
{
	int max = 0;
	int maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		if (fish[i] > max)
		{
			max = fish[i];
			maxi = i;
		}
	}
	return maxi;
}


int main()
{
	int n, k;
	while (scanf("%d", &n) && n>0)
	{
		scanf("%d", &k);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &fi[i]);
			if (fi[i] < 0)
			{
				fi[i] = 0;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &di[i]);
		}
		ti_sum[0] = 0;
		ti[0] = 0;
		for (int i = 1; i < n; ++i)
		{
			scanf("%d", &ti[i-1]);
			ti_sum[i] = ti_sum[i - 1] + ti[i - 1];
		}
		int max = -1;
		int maxspend[max_n] = { 0 };
		for (int i = 0; i < n; ++i)
		{
			int time = k * 12;
			int spend[max_n] = { 0 };
			int count = 0;
			memcpy(fish, fi, sizeof(fish));
			time -= ti_sum[i];
			while (time > 0)
			{
				int maxi = find_max_id(i + 1);
				count += fish[maxi];
				fish[maxi] -= di[maxi];
				if (fish[maxi] < 0)
				{
					fish[maxi] = 0;
				}
				++spend[maxi];
				--time;
			}
			if (count > max)
			{
				max = count;
				memcpy(maxspend, spend, sizeof(maxspend));
			}
			else if (count == max)
			{
				for (int j = 0; j < n; ++j)
				{
					if (spend[j] != maxspend[j])
					{
						if (spend[j] > maxspend[j])
						{
							memcpy(maxspend, spend, sizeof(maxspend));
						}
						break;
					}
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (i < n - 1)
			{
				printf("%d, ", maxspend[i]*5);
			}
			else
			{
				printf("%d\n", maxspend[i]*5);
			}
		}
		printf("Number of fish expected: %d\n\n", max);
	}
	return 0;
}

