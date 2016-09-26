#include "stdio.h"
#include "string.h"

#define max_row 10
#define max_col 15

typedef struct pos
{
	int i;
	int j;
}pos;

char map[max_row][max_col+1];
bool visited[max_row][max_col];
pos queue[max_col*max_row];
int max, maxi, maxj;

int visit(int tail,int i, int j)
{
	char color = map[i][j];
	if (i + 1 < max_row && !visited[i + 1][j] && map[i + 1][j] == color)
	{
		queue[tail].i = i + 1;
		queue[tail].j = j;
		visited[i + 1][j] = true;
		++tail;
	}
	if (i - 1 >= 0 && !visited[i - 1][j] && map[i - 1][j] == color)
	{
		queue[tail].i = i - 1;
		queue[tail].j = j;
		visited[i - 1][j] = true;
		++tail;
	}
	if (j + 1 < max_col && !visited[i][j + 1] && map[i][j + 1] == color)
	{
		queue[tail].i = i;
		queue[tail].j = j + 1;
		visited[i][j + 1] = true;
		++tail;
	}
	if (j - 1 >= 0 && !visited[i][j - 1] && map[i][j - 1] == color)
	{
		queue[tail].i = i;
		queue[tail].j = j - 1;
		visited[i][j - 1] = true;
		++tail;
	}
	return tail;
}

int bfs_search(int i, int j)
{
	if (!visited[i][j] && map[i][j] != 0)
	{
		int head = 0;
		int tail = 0;
		queue[tail].i = i;
		queue[tail].j = j;
		visited[i][j] = true;
		++tail;
		while (tail > head)
		{
			i = queue[head].i;
			j = queue[head].j;
			tail=visit(tail, i, j);
			++head;
		}
		return tail;
	}
	return 0;
}

void search()
{
	max = 1;
	memset(visited, false, sizeof(visited)); 
	for (int j = 0; j < max_col; ++j)
	{
		for (int i = 0; i < max_row; ++i)
		{
			int count = bfs_search(i, j);
			if (count > max )
			{
				max = count;
				maxi = i;
				maxj = j;
			}
		}
	}
}

void bfs_del(int i, int j)
{
	if ( map[i][j] != 0)
	{
		int head = 0;
		int tail = 0;
		queue[tail].i = i;
		queue[tail].j = j;
		++tail;
		while (tail > head)
		{
			i = queue[head].i;
			j = queue[head].j;
			tail = visit(tail, i, j);
			map[i][j] = 0;
			++head;
		}
	}
}

void refresh()
{
	bool ifempty[max_col] = { false };
	for (int j = 0; j < max_col; j++)
	{
		int k = 0;
		int l = 0;
		while (l < max_row)
		{
			if (map[l][j] != 0)
			{
				map[k][j] = map[l][j];
				++k;
			}
			++l;
		}
		if (k > 0)
		{
			while (k < l)
			{
				map[k][j] = 0;
				++k;
			}
		}
		else
		{
			ifempty[j] = true;
		}
	}
	for (int i = 0; i < max_row; i++)
	{
		int k = 0;
		int l = 0;
		while (l < max_col)
		{
			if (!ifempty[l])
			{
				map[i][k] = map[i][l];
				++k;
			}
			++l;
		}
		while (k < l)
		{
			map[i][k] = 0;
			++k;
		}
	}
}
void del()
{
	memset(visited, false, sizeof(visited));
	bfs_del(maxi, maxj);
	refresh();
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = max_row-1; j >=0; --j)
		{
			scanf("%s", map[j]);
		}
		printf("Game %d:\n\n", i+1);
		int score = 0;
		int remain = max_col*max_row;
		for (int j = 1; j < max_col*max_row;++j)
		{
			search();
			if (max > 1)
			{
				score += (max - 2)*(max - 2);
				remain -= max;
				printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", j, maxi+1, maxj+1, max, map[maxi][maxj], (max - 2)*(max - 2));
				del();
			}
			else
			{
				int count = 0;
				if (remain == 0)
				{
					score += 1000;
				}
				printf("Final score: %d, with %d balls remaining.\n\n", score, remain);
				break;
			}
		}
	}
	return 0;
}

