#include "stdio.h"
#include "math.h"
#include "string.h"

#define max_point 100
#define max_node 100

typedef struct point
{
	int x, y;
}point;

point pn[max_point];
point pm[max_point];
bool graph[max_node][max_node];
bool visited[max_node];
int link_n[max_node];
int link_m[max_node];
int m, n;

inline float distance(point x, point y)
{
	return sqrt(pow(float(x.x - y.x), 2) + pow(float(x.y - y.y), 2));
}

void create_graph()
{
	for (int i = 0; i < n - 1; ++i)
	{
		float c = distance(pn[i], pn[i + 1]);
		for (int j = 0; j < m; ++j)
		{
			float a = distance(pn[i], pm[j]);
			float b = distance(pn[i + 1], pm[j]);
			if (a + b <= 2 * c)
			{
				graph[i][j] = true;
			}
			else
			{
				graph[i][j] = false;
			}
		}
	}
}

bool dfs(int node_n)
{
	for (int i = 0; i < m; ++i)
	{
		if (graph[node_n][i] && !visited[i])
		{
			visited[i] = true;
			if (link_m[i] == -1 || dfs(link_m[i]))
			{
				link_m[i] = node_n;
				link_n[node_n] = i;
				return true;
			}
		}
		
	}
	return false;
}

int search()
{
	memset(link_m, -1, sizeof(link_m));
	memset(link_n, -1, sizeof(link_n));
	int match = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		memset(visited, false, sizeof(visited));
		if (dfs(i))
		{
			++match;
		}
	}
	return match;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &pn[i].x, &pn[i].y);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &pm[i].x, &pm[i].y);
	}
	create_graph();
	int match=search();
	printf("%d\n", n+match);
	for (int i = 0; i < n; ++i)
	{
		printf("%d %d ", pn[i].x, pn[i].y);
		if (link_n[i] != -1)
		{
			printf("%d %d ", pm[link_n[i]].x, pm[link_n[i]].y);
		}
	}
	printf("\n");
	return 0;
}

