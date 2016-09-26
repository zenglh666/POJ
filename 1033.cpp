#include "stdio.h"
#include "string.h"

#define max_n 10000
int cluster[max_n];
int stack[max_n];

void defrag(int n)
{
	int mov = 0;
	for (int i = 0; i < n; ++i)
	{
		if (cluster[i]!=-1 && cluster[i] != i)
		{
			int j = i;
			int k = 0;
			while (cluster[j] != -1 && cluster[j] != i)
			{
				stack[k] = j;
				++k;
				j = cluster[j];
			}
			stack[k] = j;
			++k;
			if (cluster[j] == -1)
			{
				while (k > 1)
				{
					--k;
					cluster[stack[k]] = cluster[stack[k-1]];
					printf("%d %d\n", stack[k-1]+1, stack[k]+1);
					++mov;
				}
				cluster[stack[0]] = -1;
			}
			else
			{
				int buff;
				for (int l = 0; l < n; l++)
				{
					if (cluster[l] == -1)
					{
						buff = l;
						break;
					}
				}
				stack[k] = buff;
				++k;
				while (k > 1)
				{
					--k;
					cluster[stack[k]] = cluster[stack[k - 1]];
					printf("%d %d\n", stack[k - 1] + 1, stack[k] + 1);
					++mov;
				}
				cluster[stack[0]] = cluster[buff];
				printf("%d %d\n", buff + 1, stack[0] + 1);
				++mov;
				cluster[buff] = -1;
			}
		}
	}
	if (mov == 0)
	{
		printf("No optimization needed\n");
	}
}


int main()
{
	int k, n;
	scanf("%d %d", &n, &k);
	int count = 0;
	memset(cluster, -1, sizeof(cluster));
	for (int i = 0; i < k; ++i)
	{
		int c,t;
		scanf("%d", &t);
		for (int j = 0; j < t; ++j)
		{
			scanf("%d", &c);
			cluster[c-1] = count;
			++count;
		}
	}
	defrag(n);
	return 0;
}

