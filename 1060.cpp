#include "stdio.h"
#include "string.h"

#define degree 1000

short f[degree];
short g[degree];
short m[degree*2];
short h[degree];
short q[degree];

int mul(int fl,int gl)
{
	memset(m, 0, sizeof(m));
	for (int i = 0; i <gl; ++i)
	{
		if (g[i]==1)
		{
			for (int j = i; j < i + fl; ++j)
			{
				m[j] = (m[j] + f[j-i]) % 2;
			}
		}
	}
	for (int i = degree * 2 - 1; i > -1; --i)
	{
		if (m[i] == 1)
		{
			return i+1;
		}
	}
}

int mod(int ml, int hl)
{
	memset(q, 0, sizeof(q));
	for (int i = ml-1; i >= hl-1; --i)
	{
		if (m[i] == 1)
		{
			for (int j = i; j > i - hl; --j)
			{
				m[j] = (m[j] + h[j - i + hl-1]) % 2;
			}
		}
	}
	int len = hl;
	for (int i = hl-1; i >-1; --i)
	{
		q[i] = m[i];
		if (q[i] != 0 && len == hl)
		{
			len = i + 1;
		}
	}
	return len;
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int fl, hl, gl;
		scanf("%d", &fl);
		for (int i = fl - 1; i > -1; --i)
		{
			scanf("%hd", &f[i]);
		}
		scanf("%d", &gl);
		for (int i = gl - 1; i > -1; --i)
		{
			scanf("%hd", &g[i]);
		}
		scanf("%d", &hl);
		for (int i = hl - 1; i > -1; --i)
		{
			scanf("%hd", &h[i]);
		}
		int ml=mul(fl, gl);
		int ql=mod(ml, hl);
		printf("%d", ql);
		for (int i = ql - 1; i > -1; --i)
		{
			printf(" %d", q[i]);
		}
		putchar('\n');
	}
	return 0;
}

