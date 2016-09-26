#include "stdio.h"
#define MAXN 10000

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++){
		int n;
		scanf("%d", &n);
		int id[MAXN];
		int map[MAXN][8] = { 0 };
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &id[i]);
			for (int j = 0; j < 8; ++j)
			{
				scanf("%d", &map[id[i]][j]);
			}
		}
		bool flag[MAXN] = { false };
		bool check = true;
		int  queue[MAXN];
		int head = 0;
		int tail = 0;
		queue[tail++] = id[0];
		flag[id[0]] = true;
		int maxh[MAXN][8] = { 0 };
		while (head < tail)
		{
			int idx = queue[head++];
			for (int l = 0; l < 8; ++l)
			{
				int p = map[idx][l];
				if (p != 0)
				{
					int lp = l % 2 ? l - 1 : l + 1;
					if (map[p][lp] != idx)
					{
						check = false;
						break;
					}
					if (!flag[p])
					{
						queue[tail++] = p;
						flag[p] = true;
						for (int j = 0; j < 8; ++j)
						{
							maxh[p][j] = maxh[idx][j];
						}
						maxh[p][l] = maxh[idx][l] + 1;
					}
				}
			}
			if (!check)
			{
				break;
			}
		}
		if (tail < n)
		{
			check = false;
		}
		if (!check)
		{
			printf("Inconsistent\n");
			continue;
		}
		int ans = 1;
		for (int j = 0; j<4; ++j)
		{
			int maxlen1 = 0, maxlen2 = 0;
			for (int i = 0; i<n; ++i)
			{
				int idx = id[i];
				maxlen1 = maxh[idx][2 * j]>maxlen1 ? maxh[idx][2 * j] : maxlen1;
				maxlen2 = maxh[idx][2 * j + 1]>maxlen2 ? maxh[idx][2 * j + 1] : maxlen2;
			}
			ans *= maxlen2 + maxlen1 + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}

