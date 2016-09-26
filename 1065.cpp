#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define max_stick_num 5000 

typedef struct stick
{
	int weight, length;
}stick;

stick sticks[max_stick_num];
bool visit[max_stick_num];

int compare(const void *x, const void *y)
{
	stick *a = (stick *)x;
	stick *b = (stick *)y;
	if (a->length != b->length)
	{
		return a->length - b->length;
	}
	else
	{
		return a->weight - b->weight;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int stick_num;
		scanf("%d", &stick_num);
		for (int i = 0; i < stick_num; ++i)
		{
			scanf("%d %d", &sticks[i].length, &sticks[i].weight);
		}
		qsort(sticks, stick_num, sizeof(stick), compare);
		memset(visit, false, sizeof(visit));
		int time = 0;
		bool change = true;
		while (change)
		{
			int last_visit = -1;
			change = false;
			for (int i = 0; i < stick_num; ++i)
			{
				if (!visit[i])
				{
					if (!change)
					{
						last_visit = i;
						visit[i] = true;
						change = true;
						++time;
					}
					else if (sticks[i].weight >= sticks[last_visit].weight)
					{
						last_visit = i;
						visit[i] = true;
					}
				}
			}
		}
		printf("%d\n", time);
	}
	return 0;
}

