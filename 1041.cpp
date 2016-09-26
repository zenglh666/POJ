#include "stdio.h"
#include "string.h"
#define max_street 1996
#define max_cross 46

typedef struct cross
{
	int d;
	int map[max_street];
}cross;

bool visited[max_street];
cross c[max_cross];
int stack[max_street];
int stack_top;
int home;

void dfs(int cro)
{
	for (int i = 1; i < max_street; ++i)
	{
		if (c[cro].map[i] && !visited[i])
		{
			visited[i] = true;
			dfs(c[cro].map[i]);
			stack[stack_top] = i;
			++stack_top;
		}
	}
}

int main()
{
	int x,y,z;
	while (scanf("%d %d", &x, &y) && (x != 0 || y != 0))
	{
		memset(c, 0, sizeof(c));
		home = x < y ? x : y;
		while (x != 0 || y != 0)
		{
			scanf("%d", &z);
			++c[x].d;
			c[x].map[z] = y;
			++c[y].d;
			c[y].map[z] = x;
			scanf("%d %d", &x, &y);
		}
		bool able = true;
		for (int i = 1; i < max_cross; ++i)
		{
			if (c[i].d % 2 != 0)
			{
				able = false;
				break;
			}
		}
		if (!able)
		{
			printf("Round trip does not exist.\n");
		}
		else
		{
			memset(visited, false, sizeof(visited));
			stack_top = 0;
			dfs(home);
			for (int i = stack_top-1; i >-1; --i)
			{
				printf("%d ", stack[i]);
			}
			printf("\n");
		}
	}
	return 0;
}

