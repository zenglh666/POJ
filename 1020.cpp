#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define max_s 41
#define max_es 10

int size_count[max_s];
int col_fill[max_s];

bool dfs(int s, int n)
{
	if (n == 0)
	{
		return true;
	}
	else
	{
		int min_col = max_s;
		int min_col_id = -1;
		for (int i =0 ; i < s; i++)
		{
			if (min_col > col_fill[i])
			{
				min_col = col_fill[i];
				min_col_id = i;
			}
		}
		for (int i = max_es; i > 0; i--)
		{
			if (size_count[i] > 0)
			{
				if (s - min_col_id >= i && s - min_col >= i)
				{
					int wide = 0;
					for (int j = min_col_id ; j < min_col_id + i; j++)
					{
						if (col_fill[j] <= min_col)
						{
							wide++;
						}
						else
						{
							break;
						}
					}
					if (wide >= i)
					{
						for (int j = min_col_id ; j < min_col_id + i; j++)
						{
							col_fill[j] += i;
						}
						size_count[i]--;
						if (dfs(s, n - 1))
						{
							return true;
						}
						size_count[i]++;
						for (int j = min_col_id ; j < min_col_id + i; j++)
						{
							col_fill[j] -= i;
						}
					}
				}
			}
		}
		return false;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int s, n;
		scanf("%d %d", &s, &n);
		memset(size_count, 0, sizeof(size_count));
		memset(col_fill, 0, sizeof(col_fill));
		int area = 0;
		int cnt=0;
		for (int i = 0; i < n; i++)
		{
			int size;
			scanf("%d", &size);
			area += size*size;
			if (size > s / 2)
			{
				cnt++;
			}
			size_count[size]++;
		}
		if (area != s*s || cnt>1)
		{
			printf("HUTUTU!\n");
		}
		else
		{
			if (dfs(s, n))
			{
				printf("KHOOOOB!\n");
			}
			else
			{
				printf("HUTUTU!\n");
			}
		}
		
	}
	return 0;
}

