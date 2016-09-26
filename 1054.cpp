#include "stdio.h"
#include "stdlib.h"

#define max_points 5000
#define max_length 5001

struct point
{
	int x, y;
}points[max_points];

bool visit[max_length][max_length];
int r, c;

int compare(const void *x, const void *y)
{
	point *a = (point *)x;
	point *b = (point *)y;
	if (a->y == b->y)
	{
		return a->x - b->x;
	}
	else
	{
		return a->y - b->y;
	}
}

inline bool inplace(int i, int j)
{
	return (i > 0 && i <= r && j > 0 && j <= c);
}

int main()
{
	scanf("%d %d", &r, &c);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &points[i].x, &points[i].y);
		visit[points[i].x][points[i].y] = true;
	}
	qsort(points, n, sizeof(point), compare);
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int count = 0;
			int disx = points[j].x - points[i].x;
			int disy = points[j].y - points[i].y;
			if (!inplace(points[i].x - disx, points[i].y - disy))
			{
				int tmpx = points[j].x+disx;
				int tmpy = points[j].y+disy;
				while (inplace(tmpx, tmpy) && visit[tmpx][tmpy])
				{
					++count;
					tmpx += disx;
					tmpy += disy;
				}
				if (inplace(tmpx, tmpy))
				{
					count = 0;
				}
				if (count > max)
				{
					max = count;
				}
			}
		}
	}
	if (max>0)
		printf("%d\n", max+2);
	else
		printf("0\n");
	return 0;
}

