#include "stdio.h"
#include "math.h"

#define eps 1e-8
#define max_point_count 30

typedef struct point
{
	double x, y;
}point;

typedef struct line
{
	point p1, p2;
}line;

line lines[max_point_count];
point des;

inline double cross(point p1, point p2)
{
	return p1.x*p2.y - p1.y*p2.x;
}

bool is_intersection(line l1, line l2)
{
	point a,b,c;
	a.x = l1.p1.x - l2.p1.x;
	a.y = l1.p1.y - l2.p1.y;
	b.x = l1.p2.x - l2.p1.x;
	b.y = l1.p2.y - l2.p1.y;
	c.x = l2.p2.x - l2.p1.x;
	c.y = l2.p2.y - l2.p1.y;
	if (cross(a, c)*cross(b, c) < -eps)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int compute(int n)
{
	line l;
	l.p1 = des;
	int count;
	int max = max_point_count * 2;
	for (int i = 0; i < n; ++i)
	{
		l.p2 = lines[i].p1;
		count = 0;
		for (int j = 0; j < n; ++j)
		{
			if (is_intersection(l, lines[j]))
			{
				++count;
			}
		}
		if (count < max)
		{
			max = count;
		}
		l.p2 = lines[i].p2;
		count = 0;
		for (int j = 0; j < n; ++j)
		{
			if (is_intersection(l, lines[j]))
			{
				++count;
			}
		}
		if (count < max)
		{
			max = count;
		}
	}
	return max;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf %lf %lf %lf", &lines[i].p1.x, &lines[i].p1.y,
			&lines[i].p2.x, &lines[i].p2.y);
	}
	scanf("%lf %lf", &des.x, &des.y);
	int count = compute(n);
	if (n == 0)
	{
		printf("Number of doors = 1\n");
	}
	else
	{
		printf("Number of doors = %d\n", count + 1);
	}
	return 0;
}

