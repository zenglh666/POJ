#include "stdio.h"

#define max_item 6

int item[max_item];

void cannot_divide(int i)
{
	printf("Collection #%d:\nCan't be divided.\n\n",i);
}

void can_divide(int i)
{
	printf("Collection #%d:\nCan be divided.\n\n", i);
}

bool dfs(int value, int pos)
{
	if (value == 0)
	{
		return true;
	}
	else
	{
		for (int i = pos; i > -1; i--)
		{
			if (value >= i+1)
			{
				if (item[i] > 0)
				{
					item[i]--;
					if (dfs(value - i-1, i))
					{
						return true;
					}
				}
			}
		}
		return false;
	}
}

int main()
{
	int count = 0;
	while (scanf("%d %d %d %d %d %d", &item[0], &item[1], &item[2], &item[3], &item[4], &item[5]))
	{
		count++;
		int sum = 0;
		for (int i = 0; i < max_item; i++)
		{
			sum += item[i]*(i+1);
		}
		if (sum == 0)
		{
			break;
		}
		else
		{
			if (sum % 2 == 1)
			{
				cannot_divide(count);
			}
			else
			{
				int half = sum / 2;
				if (dfs(half, max_item - 1))
				{
					can_divide(count);
				}
				else
				{
					cannot_divide(count);
				}
			}
		}
	}
	return 0;
}

