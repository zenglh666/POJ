#include "stdio.h"

#define max_k 14

int joseph[14] = { 0 };

int main()
{
	int k;
	while (scanf("%d", &k) && k)
	{
		if (joseph[k] != 0)
		{
			printf("%d\n", joseph[k]);
		}
		else
		{
			int m = 1;
			int kill[max_k];
			kill[0] = 0;
			for (int i = 1; i <= k; i++)
			{
				kill[i] = (kill[i - 1] + m - 1) % (2 * k - i + 1);
				if (kill[i] < k)
				{
					i = 0;
					m++;
				}
			}
			joseph[k] = m;
			printf("%d\n", m);
		}
	}
	return 0;
}

