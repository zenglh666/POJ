#include "string.h"
#include "stdio.h"
#define UP 0
#define DOWN 1
#define maxn 25

long long C[maxn][maxn][2];

void Init()
{
	memset(C, 0, sizeof(C));
	C[1][1][UP] = C[1][1][DOWN] = 1;
	int i, j, k;
	for (i = 2; i < maxn; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
			for (k = j; k < i; ++k)
			{
				C[i][j][UP] += C[i - 1][k][DOWN];
			}

			for (k = 1; k < j; ++k)
			{
				C[i][j][DOWN] += C[i - 1][k][UP];
			}
		}
	}
}

void Print(int n, long long cc)
{
	long long skipped = 0, oldVal;
	int seq[maxn]; 
	int used[maxn]; 
	memset(used, 0, sizeof(used));
	for (int i = 1, k; i <= n; ++i)
	{ 
		int No = 0;
		for (k = 1; k <= n; ++k)
		{ 
			oldVal = skipped;
			if (!used[k])
			{
				++No; 
				if (i == 1)
				{
					skipped += C[n][No][UP] + C[n][No][DOWN];
				}
				else if (i == 2)
				{
					if (k > seq[i - 1])
					{
						skipped += C[n - i + 1][No][DOWN];
					}
					else
					{
						skipped += C[n - i + 1][No][UP];
					}
				}
				else
				{
					if (k > seq[i - 1] && seq[i - 2] > seq[i - 1])
					{
						skipped += C[n - i + 1][No][DOWN];
					}
					else if (k < seq[i - 1] && seq[i - 2] < seq[i - 1])
					{
						skipped += C[n - i + 1][No][UP];
					}
				}
				if (skipped >= cc)
				{
					break;
				}
			}
		}
		used[k] = 1;
		seq[i] = k;
		skipped = oldVal;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (i < n) 
		{
			printf("%d ", seq[i]);
		}
		else
		{
			printf("%d\n", seq[i]);
		}
	}
		
}


int main()
{
	Init();
	int k, n;
	long long c;
	scanf("%d", &k);
	while (k>0)
	{
		scanf("%d %lld", &n, &c);
		Print(n, c);
		--k;
	}
	return 0;
}

