#include"stdio.h"
#include"string.h"

#define max_n  362880
#define aim  46234
#define grid_l 3
#define grid_num grid_l*grid_l 
int movement[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
char indexs[5] = "udlr";

struct Node
{
	int s[grid_num];
	int loc;
	int status;
};

int fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };
bool vis[max_n];
Node q[max_n];
char path[max_n];
int parent[max_n];

int cantor(int s[])
{
	int sum = 0;
	for (int i = 0; i<grid_num; i++)
	{
		int num = 0;
		for (int j = i + 1; j<grid_num; j++)
			if (s[j]<s[i])num++;
		sum += (num*fac[grid_num - i - 1]);
	}
	return sum + 1;
}

bool bfs(Node ncur)
{
	if (ncur.status == aim)
	{
		return true;
	}
	else
	{
		memset(vis, false, sizeof(vis));
		Node cur, next;
		int start = 0;
		int end = 0;
		q[end] = ncur;
		++end;
		while (start != end)
		{
			cur = q[start];
			++start;
			int x = cur.loc / 3;
			int y = cur.loc % 3;
			for (int i = 0; i<4; i++)
			{
				int tx = x + movement[i][0];
				int ty = y + movement[i][1];
				if (tx >= 0 && tx < grid_l && ty >= 0 && ty < grid_l)
				{
					next = cur;
					next.loc = tx * 3 + ty;
					next.s[cur.loc] = next.s[next.loc];
					next.s[next.loc] = 0;
					next.status = cantor(next.s);
					if (!vis[next.status])
					{
						vis[next.status] = true;
						path[next.status] = indexs[i];
						parent[next.status] = cur.status;
						if (next.status == aim)
						{
							return true;
						}
						else
						{
							q[end] = next;
							++end;
						}
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	char ch[grid_num];
	Node ncur;
	path[aim] = -1;
	while (scanf("%s",ch)==1)
	{
		if (ch[0] == 'x') 
		{ 
			ncur.s[0] = 0; 
			ncur.loc = 0; 
		}
		else ncur.s[0] = ch[0] - '0';
		for (int i = 1; i<9; i++)
		{
			scanf("%s", ch);
			if (ch[0] == 'x')
			{
				ncur.s[i] = 0;
				ncur.loc = i;
			}
			else
			{
				ncur.s[i] = ch[0] - '0';
			}
		}
		ncur.status = cantor(ncur.s);
		parent[ncur.status] = -1;
		if (bfs(ncur))
		{
			char trail[1000];
			int u = aim;
			int v = 0;;
			while (u != ncur.status)
			{
				trail[v] = path[u];
				++v;
				u = parent[u];
			}
			for (int i = v - 1; i > -1; --i)
			{
				putchar(trail[i]);
			}
			putchar('\n');
		}
		else
		{
			printf("unsolvable\n");
		}
	}
	return 0;
}