#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define max_stick_len 64

int stick[max_stick_len];
int stick_len;
bool visit[max_stick_len];

int compare(const void *a, const void *b)
{
	int *x = (int *)a;
	int *y = (int *)b;
	return *y - *x;
}

bool dfs(int pos,int remain_len,int init_len,int used_stick)
{
	if ( used_stick==stick_len)
	{
		return true;
	}
	else
	{
		int last_stick = -1;
		for (int i = pos; i < stick_len; i++)
		{
			if (!visit[i] && stick[i] != last_stick)
			{
				visit[i] = true;
				last_stick = stick[i];
				if (remain_len > stick[i])
				{
					if (dfs(i, remain_len - stick[i],init_len,used_stick+1))
					{
						return true;
					}
				}
				else if (remain_len == stick[i])
				{
					if (dfs(0, init_len, init_len, used_stick + 1))
					{
						return true;
					}
				}
				visit[i] = false;
				if (remain_len == init_len)
				{
					break;
				}
			}
		}
		return false;
	}
	
}
int main()
{
	while (scanf("%d", &stick_len) && stick_len)
	{
		int sum = 0;
		for (int i = 0; i < stick_len; i++)
		{
			scanf("%d", &stick[i]);
			sum += stick[i];
		}
		qsort(stick, stick_len, sizeof(int), compare);
		int init_len=sum;
		for (int i = stick[stick_len-1]; i < sum; i++)
		{
			if (sum%i == 0)
			{
				memset(visit, false, sizeof(visit));
				if (dfs(0, i,i,0))
				{
					init_len = i;
					break;
				}
			}
		}
		printf("%d\n", init_len);
	}
	return 0;
}

