#include "stdio.h"
#include "math.h"
int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) == 2)
	{
		int p = 1;
		int q = 0;
		for (int i = 1; i <= b; ++i)
		{
			int pt = int(double(i*a) / double(b) + 0.5);
			if (q*abs(a*i - b*pt) < i*abs(a*q - b*p))
			{
				p = pt;
				q = i;
				printf("%d/%d\n", p, q);
			}
			if (a*q == b*p)
			{
				break;
			}
		}
		putchar('\n');
	}
	return 0;
}
