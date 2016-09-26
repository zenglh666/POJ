#include "stdio.h"
#define max_length 1001
#define blank 4

int dp[max_length][max_length];
int code[5][5] = 
{ 
	{ 5, -1, -2, -1, -3 },
	{ -1, 5, -3, -2, -4 },
	{ -2, -3, 5, -2, -2 },
	{ -1, -2, -2, 5, -1 },
	{ -3, -4, -2, -1, 0 } 
};

void convert(int *ca,char *a, int len_a)
{
	for (int i = 1; i <= len_a; ++i)
	{
		switch (a[i])
		{
		case 'A':
			ca[i] = 0;
			break;
		case 'C':
			ca[i] = 1;
			break;
		case 'G':
			ca[i] = 2;
			break;
		case 'T':
			ca[i] = 3;
			break;
		}
	}
}

inline int max3(int a, int b, int c)
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int len_a, len_b;
		char a[max_length], b[max_length];
		scanf("%d %s", &len_a, a + 1);
		scanf("%d %s", &len_b, b + 1);
		int ca[max_length], cb[max_length];
		convert(ca, a, len_a);
		convert(cb, b, len_b);
		dp[0][0] = 0;
		for (int i = 1; i <= len_a; ++i)
		{
			dp[i][0] = dp[i - 1][0] + code[ca[i]][blank];
		}
		for (int i = 1; i <= len_b; ++i)
		{
			dp[0][i] = dp[0][i - 1] + code[blank][cb[i]];
		}
		for (int i = 1; i <= len_a; ++i)
		{
			for (int j = 1; j <= len_b; ++j)
			{
				int tmp1 = dp[i][j - 1] + code[blank][cb[j]];
				int tmp2 = dp[i - 1][j] + code[ca[i]][blank];
				int tmp3 = dp[i - 1][j - 1] + code[ca[i]][cb[j]];
				dp[i][j] = max3(tmp1, tmp2, tmp3);
			}
		}
		printf("%d\n", dp[len_a][len_b]);
	}
	return 0;
}

