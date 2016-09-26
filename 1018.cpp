#include "stdio.h"
#include "stdlib.h"

#define max_t 10
#define max_n 100
#define max_m 100

typedef struct device
{
	int band, price,kind;
}device;

device dev[max_n*max_m];

int compare(const void *a, const void *b)
{
	device *x = (device *)a;
	device *y = (device *)b;
	if (x->band != y->band)
	{
		return x->band - y->band;
	}
	else if (x->price != y->price)
	{
		return x->price - y->price;
	}
	else
	{
		return x->kind - y->kind;
	}
}

int main()
{
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		int count = 0;
		int max_band[max_m] = { 0 };
		for (int j = 0; j < n; j++)
		{
			int m;
			scanf("%d", &m);
			for (int k = 0; k < m; k++)
			{
				dev[count].kind = j;
				scanf("%d %d", &dev[count].band, &dev[count].price);
				if (dev[count].band > max_band[j])
				{
					max_band[j] = dev[count].band;
				}
				count++;
			}
		}
		qsort(dev, count, sizeof(device), compare);
		double band_div_price = 0;
		for (int j = 0; j < count-n+1; j++)
		{
			bool visit[max_n] = {false};
			visit[dev[j].kind] = true;
			double price = (double)dev[j].price;
			int kind = 1;
			bool trim = false;
			for (int k = j+1; k < count; k++)
			{
				if (!visit[dev[k].kind])
				{
					if (max_band[dev[k].kind] < dev[j].band)
					{
						trim = true;
						break;
					}
					visit[dev[k].kind] = true;
					price += (double)dev[k].price;
					kind ++;
				}
			}
			if (kind < n || trim)
			{
				break;
			}
			if (band_div_price < dev[j].band / price)
			{
				band_div_price = dev[j].band / price;
			}
		}
		printf("%.3f\n", band_div_price);
	}
	return 0;
}

