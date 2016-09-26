#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define fix 400
#define max_grade 20
#define max_m 20
#define max_n 200

int dp[max_m + 1][fix*2 + 1];
int path[max_m + 1][fix*2 + 1];
int grades[max_n][2];
int grades_sum[max_n];
int grades_diff[max_n];

bool not_use(int i, int j, int k)
{
	while (i > 0)
	{
		if (k == path[i][j])
		{
			return false;
		}
		else
		{
			j = j-grades_diff[path[i][j]];
			i--;
		}
	}
	return true;
}

void dynamic_programming(int m,int n)
{
	dp[0][fix] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < fix * 2 + 1; j++)
		{
			if (dp[i-1][j]>=0)
			{
				for (int k = 0; k < n; k++)
				{
					if (dp[i - 1][j] + grades_sum[k]>dp[i][j + grades_diff[k]])
					{
						if (not_use(i-1, j, k))
						{
							dp[i][j + grades_diff[k]] = dp[i - 1][j] + grades_sum[k];
							path[i][j + grades_diff[k]] = k;
						}
					}
				}
			}
		}
	}
}

int compare(const void *a, const void *b)
{
	int *x = (int *)a;
	int *y = (int *)b;
	return *x - *y;
}

int main()
{
	int m, n,count;
	count = 0;
	while (scanf("%d %d", &n, &m) &&  n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &grades[i][0], &grades[i][1]);
			grades_sum[i] = grades[i][0] + grades[i][1];
			grades_diff[i] = grades[i][0] - grades[i][1];
		}
		memset(dp, -1, sizeof(dp));
		memset(path, -1, sizeof(path));
		dynamic_programming(m, n);
		int diff,sum;
		for (int i = 0; i <= fix; i++)
		{
			if (dp[m][fix - i] >= 0 || dp[m][fix + i] >= 0)
			{
				int ind = dp[m][fix - i]>dp[m][fix + i] ? -1 : 1;
				diff = i*ind;
				sum = dp[m][fix + diff];
				break;
			}
		}
		count++;
		printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",
			count, (sum + diff) / 2, (sum - diff) / 2);

		int id[max_m];
		int j = diff;
		for (int i = m; i >0; i--)
		{
			id[i-1] = path[i][fix+j];
			j = j - grades_diff[id[i-1]];
		}
		qsort(id, m, sizeof(int), compare);
		for (int i = 0; i < m; i++)
		{
			printf(" %d", id[i]+1);
		}
		printf("\n\n");
	}
	return 0;
}

