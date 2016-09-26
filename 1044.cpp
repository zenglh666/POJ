#include "stdio.h"
#include "string.h"

#define max_year 10000

int count[max_year];

int main()
{
	int n;
	int cas = 1;
	while (scanf("%d", &n) && n > 0)
	{
		memset(count, 0, sizeof(count));
		for (int i = 0; i < n; ++i)
		{
			int y1, y2, y;
			scanf("%d %d %d", &y, &y1, &y2);
			int gap = y2 - y1;
			while (y < max_year)
			{
				++count[y];
				y += gap;
			}
		}
		bool find = false;
		for (int i = 0; i < max_year; ++i)
		{
			if (count[i] == n)
			{
				printf("Case #%d:\nThe actual year is %d.\n\n", cas,i);
				find = true;
				break;
			}
		}
		if (!find)
		{
			printf("Case #%d:\nUnknown bugs detected.\n\n", cas);
		}
		++cas;
	}
	return 0;
}

