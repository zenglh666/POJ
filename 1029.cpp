
#include<stdio.h>
#include<string.h>
#include<math.h>
int num[1010], used[1010], a[1010];
int k, n, l, pos;
int judge()
{
	int i, j1, max = 0;
	for (i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			if (abs(num[i])>max)
			{
				max = abs(num[i]);
				pos = i;
			}
		}
	}
	j1 = 0;
	for (i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			if (abs(num[i]) == max)
				j1++;
		}
	}
	if (j1 == 1)
		return 1;
	else
		return 0;
}
int main()
{
	int i, j, p;
	char ch;

	while (scanf("%d%d", &n, &k) != EOF)
	{
		memset(used, 0, sizeof(used));
		memset(num, 0, sizeof(num));
		while (k--)
		{

			scanf("%d", &l);
			for (i = 1; i <= 2 * l; i++)
				scanf("%d", &a[i]);
			getchar();
			scanf("%c", &ch);
			switch (ch)
			{
			case '<':
				for (i = 1; i <= l; i++)
					if (!used[a[i]]) num[a[i]]--;
				for (i = l + 1; i <= 2 * l; i++)
					if (!used[a[i]]) num[a[i]]++;
				break;
			case '>':
				for (i = l + 1; i <= 2 * l; i++)
					if (!used[a[i]]) num[a[i]]--;
				for (i = 1; i <= l; i++)
					if (!used[a[i]]) num[a[i]]++;
				break;
			case '=':
				for (i = 1; i <= 2 * l; i++)
					used[a[i]] = 1;
				break;
			}
		}
		j = 0;
		for (i = 1; i <= n; i++)
		{
			if (used[i] == 0)
			{
				p = i; j++;
			}
		}
		if (j == 1)
		{
			printf("%d\n", p);
			continue;
		}
		if (judge())
		{
			printf("%d\n", pos);
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}

