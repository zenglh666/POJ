#include "stdio.h"
#include "math.h"

#define max_p 16
typedef struct pixel
{
	int r, g, b;
}pixel;


pixel pi[max_p];

inline double distance(pixel a, pixel b)
{
	return sqrt(double((a.r - b.r)*(a.r - b.r) + (a.g - b.g)*(a.g - b.g) + (a.b - b.b)*(a.b - b.b)));
}


int main()
{
	for (int i = 0; i < max_p; ++i)
	{
		scanf("%d %d %d", &pi[i].r, &pi[i].g, &pi[i].b);
	}
	pixel p;
	while (scanf("%d %d %d", &p.r, &p.g, &p.b) && p.r != -1 && p.g != -1 && p.b != -1)
	{
		double min_dis = 100000000.0;
		int min_i;
		for (int i = 0; i < max_p; ++i)
		{
			double dis = distance(pi[i], p);
			if (dis < min_dis)
			{
				min_dis = dis;
				min_i = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", p.r, p.g, p.b, pi[min_i].r, pi[min_i].g, pi[min_i].b);
	}
	return 0;
}

