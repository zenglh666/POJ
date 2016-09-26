#include"stdio.h"
#include"string.h"

#define N 59050
#define max_n 12
#define max_m 151

int tri[max_n];
int dp[2][N];
int info_pre[max_n];
int info_cur[max_n];
int map[max_m][max_n];
int m, n,pass;

void get_tri()
{
	tri[1] = 1;
	for (int i = 2; i < max_n; ++i)
	{
		tri[i] = tri[i - 1] * 3;
	}
}

int switch_ten(int p[max_n])
{
	int ans=0;
	for (int i = 1; i <= m; ++i)
	{
		ans += p[i] * tri[i];
	}
	return ans;
}

void switch_tri(int t, int p[max_n])
{
	for (int i = 1; i <= m; ++i)
	{
		p[i] = t % 3;
		t /= 3;
	}
}

inline int max(int a, int b)
{
	return a > b ? a : b;
}

void dfs(int i, int j, int cnt, int stata)
{
	int k;
	dp[i % 2][stata] = max(dp[i % 2][stata], cnt);
	if (j >= m) return;
	if (!info_pre[j] && !info_pre[j + 1] && !info_cur[j] && !info_cur[j + 1])
	{
		info_cur[j] = info_cur[j + 1] = 2;
		k = switch_ten(info_cur);
		dfs(i, j + 2, cnt + 1, k);
		info_cur[j] = info_cur[j + 1] = 0;
	}
	if (j < m - 1 && !info_cur[j] && !info_cur[j + 1] && !info_cur[j + 2])
	{
		info_cur[j] = info_cur[j + 1] = info_cur[j + 2] = 2;
		k = switch_ten(info_cur);
		dfs(i, j + 3, cnt + 1, k);
		info_cur[j] = info_cur[j + 1] = info_cur[j + 2] = 0;
	}
	dfs(i, j + 1, cnt, stata);
}

int main()
{
	get_tri();
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(map, 0, sizeof(map));
		memset(dp, -1, sizeof(dp));
		int k;
		scanf("%d %d %d", &n, &m, &k);
		while (k--)
		{
			int i, j;
			scanf("%d %d", &i, &j);
			map[i][j] = 1;
		}
		for (int i = 1; i <= m; ++i)
		{
			info_pre[i] = map[1][i] + 1;
		}
		int state = switch_ten(info_pre);
		dp[1][state] = 0;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 0; j < tri[m + 1]; ++j)
			{
				dp[i % 2][j] = -1;
			}
			for (int j = 0; j < tri[m + 1]; ++j)
			{
				if (dp[(i + 1) % 2][j] != -1)
				{
					switch_tri(j, info_pre);
					for (int l = 1; l <= m; ++l)
					{
						if (map[i][l])
						{
							info_cur[l] = 2;
						}
						else
						{
							info_cur[l] = max(info_pre[l] - 1, 0);
						}
					}
					dfs(i, 1, dp[(i + 1) % 2][j], switch_ten(info_cur));
				}
			}
		}
		int ans=0;
		for (int i = 0; i<tri[m + 1]; i++){
			ans = max(ans, dp[n % 2][i]);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}