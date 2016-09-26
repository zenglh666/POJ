#include"stdio.h"
#include"string.h"

#define grid_num 6
#define stick_num grid_num*(grid_num+1)*2
#define square_num grid_num*(grid_num+1)*(grid_num*2+1)/6
#define total_num stick_num * square_num
#define inf 10000

int L[total_num], R[total_num], S[total_num], D[total_num], U[total_num], C[total_num], O[total_num], H[total_num];
bool mark[stick_num][square_num];
bool vis[square_num];
int ans;

void remove(int c)
{
	for (int i = D[c]; i != c; i = D[i])
	{
		L[R[i]] = L[i];
		R[L[i]] = R[i];
	}
}
void resume(int c)
{
	for (int i = D[c]; i != c; i = D[i])
	{
		L[R[i]] = i;
		R[L[i]] = i;
	}
}
int geth()
{
	bool has[square_num];
	memset(has, false, sizeof(has));
	int res = 0;
	for (int i = R[0]; i != 0; i = R[i])
	{
		if (!has[i])
		{
			res++;
			for (int j = D[i]; j != i; j = D[j])
			{
				for (int k = R[j]; k != j; k = R[k])
				{
					has[C[k]] = true;
				}
			}
		}
	}
	return res;
}

void dfs(int k)
{
	if (!R[0])
	{
		ans = k < ans ? k : ans;
		return;
	}
	else if (k + geth() >= ans)
	{
		return;
	}
	else
	{
		int c = R[0];
		for (int t = R[0], ms = inf; t != 0; t = R[t])
			if (S[t]<ms)
				ms = S[t], c = t;
		for (int i = D[c]; i != c; i = D[i])
		{
			remove(i);
			for (int j = R[i]; j != i; j = R[j])
			{
				remove(j);
				S[C[j]]--;
			}
			dfs(k + 1);
			for (int j = L[i]; j != i; j = L[j])
			{
				resume(j);
				S[C[j]]++;
			}
			resume(i);
		}
	}
}
void link(int r, int c,int col)
{
	int cnt = r*(col + 1) + c;
	D[cnt] = D[c];
	U[D[c]] = cnt;
	U[cnt] = c;
	D[c] = cnt;
	C[cnt] = c;
	++S[c];
	if (H[r] ==-1 )
	{
		H[r] = L[cnt] = R[cnt] = cnt;
	}
	else
	{
		R[cnt] = R[H[r]];
		L[R[H[r]]] = cnt;
		L[cnt] = H[r];
		R[H[r]] = cnt;
	}
}

void init(int col,int n)
{
	for (int i = 0; i <= col; i++)
	{
		U[i] = D[i] = i;
		L[i + 1] = i;
		R[i] = i + 1;
		C[i] = i;
		S[i] = 0;
	}
	R[col] = 0;
	L[0] = col;
	memset(mark, false, sizeof(mark));
	int i, j, k, si, num = 0, c = 1;
	for (si = 1; si <= n; si++)
	{
		for (i = 1; i <= n - si + 1; i++)
		{
			for (j = 1; j <= n - si + 1; j++)
			{
				for (k = 0; k<si; k++)
				{
					mark[(i - 1)*(2 * n + 1) + j + k][c] = true;
					mark[(i - 1 + si)*(2 * n + 1) + j + k][c] = true;
					mark[i*n + (i - 1)*(n + 1) + j + k*(2 * n + 1)][c] = true;
					mark[i*n + (i - 1)*(n + 1) + j + k*(2 * n + 1) + si][c] = true;
				}
				c++;
			}
		}
	}
}
int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int num;
		int row = 2 * n*(n + 1);
		int col = n*(n + 1)*(2 * n + 1) / 6;
		init(col,n);
		scanf("%d", &num);
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < num; i++)
		{
			int r;
			scanf("%d", &r);
			for (int j = 1; j <= col; j++)
			{
				if (mark[r][j])
				{
					if (!vis[j])
					{
						vis[j] = true;
						R[L[j]] = R[j];
						L[R[j]] = L[j];
						R[j] = L[j] = 0;
					}
				}
			}
		}
		memset(H, -1, sizeof(H));
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (mark[i][j] && !vis[j])
				{
					link(i, j,col);
				}
			}
		}
		ans = inf;
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}