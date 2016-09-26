#include "stdio.h"
#include "string.h"

#define maxn 105
#define inf 0x3f3f3f3f

int n, array[maxn][maxn];
int f[maxn][maxn][maxn];

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int work()
{
	memset(f, 0, sizeof(f));
	int ret = -inf;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int sum = 0;
			for (int k = j; k <= n; k++)
			{
				sum += array[i][k];
				if (f[i - 1][j][k] > 0)
				{
					f[i][j][k] = f[i - 1][j][k] + sum;
				}
				else
				{
					f[i][j][k] = sum;
				}
				ret = max(ret, f[i][j][k]);
			}
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	printf("%d\n", work());
	return 0;
}
