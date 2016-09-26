#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define max_n 101
#define max_k 101
#define max_t 30001

typedef struct gangster
{
	int time, prosperity, stoutness;
}gangster;

gangster gangsters[max_n];
int dp[2][max_k];

int cmp(const void *a, const void *b)
{
	gangster* x = (gangster *)a;
	gangster* y = (gangster *)b;
	if (x->time != y->time)
	{
		return x->time - y->time;
	}
	else if (x->stoutness != y->stoutness)
	{
		return x->stoutness - y->stoutness;
	}
	else
	{
		return x->prosperity - y->prosperity;
	}
}

inline int max2(int a, int b)
{
	return a > b ? a : b;
}

inline int max3(int a, int b, int c)
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
int main()
{
	int n, k,t;
	scanf("%d %d %d", &n, &k, &t);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &gangsters[i].time);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &gangsters[i].prosperity);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &gangsters[i].stoutness);
	}
	qsort(gangsters, n, sizeof(gangster), cmp);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	int w = 0;
	int l,u;
	for (int i = 1; i <= t; ++i)
	{
		l = i % 2;
		u = 1 - l;
		while (gangsters[w].time < l)
		{
			++w;
		}
		dp[l][0] = max2(dp[u][0], dp[u][1]);
		dp[l][k] = max2(dp[u][k], dp[u][k-1]);
		for (int j = 1; j < k; ++j)
		{
			dp[l][j]=max3(dp[u][j - 1], dp[u][j], dp[u][j + 1]);
		}
		while (gangsters[w].time == i)
		{
			if (dp[l][gangsters[w].stoutness] != -1)
			{
				dp[l][gangsters[w].stoutness] += gangsters[w].prosperity;
			}
			++w;
		}
	}
	int ans = -1;
	for (int i = 0; i <= k; i++)
	{
		ans = max2(ans, dp[l][i]);
	}
	printf("%d\n", ans);
	return 0;
}

