#include "stdio.h"


int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m, y, d;
		scanf("%d %d %d", &y, &m, &d);
		if ((m == 11 || m == 9) && d == 30)
		{
			printf("YES\n");
			continue;
		}
		if ((m & 1) ^ (d & 1))
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}
