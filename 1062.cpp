#include "stdio.h"
#include "string.h"

#define max_item 101
#define max_price 10001

typedef struct item
{
	int price, level, change_num;
	int change_obj[max_item];
	int change_price[max_item];
}item;

item items[max_item];
bool visit[max_item];

int dijkstra(int n)
{
	int price[max_item];
	int minprice = max_price;
	int mini = -1;
	for (int i = 1; i <= n; ++i)
	{
		price[i] = max_price;
		if (!visit[i] && items[i].price < minprice)
		{
			mini = i;
			minprice = items[i].price;
		}
	}
	price[mini] = minprice;
	visit[mini] = true;
	for (int k = 1; k < n; ++k)
	{
		minprice = max_price;
		mini = -1;
		for (int i = 1; i <= n; ++i)
		{
			if (!visit[i])
			{
				int itemminprice = items[i].price;
				int itemminj = -1;
				for (int j = 0; j < items[i].change_num; ++j)
				{
					if (price[items[i].change_obj[j]] + items[i].change_price[j] < itemminprice)
					{
						itemminj = j;
						itemminprice = price[items[i].change_obj[j]] + items[i].change_price[j];
					}
				}
				if (itemminprice < minprice)
				{
					minprice = itemminprice;
					mini = i;
				}
			}
		}
		if (mini != -1)
		{
			price[mini] = minprice;
			visit[mini] = true;
		}
		else
			break;
	}
	return price[1];
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d %d", &items[i].price, &items[i].level, &items[i].change_num);
		for (int j = 0; j < items[i].change_num; ++j)
		{
			scanf("%d %d", &items[i].change_obj[j], &items[i].change_price[j]);
		}
	}
	int minprice = max_price;
	for (int i = 1; i <= n; ++i)
	{
		memset(visit, false,sizeof(visit));
		int maxlevel = items[i].level;
		for (int j = 1; j <= n; ++j)
		{
			if (items[j].level > maxlevel || items[j].level < maxlevel - m)
			{
				visit[j] = true;
			}
		}
		int iprice=dijkstra(n);
		if (iprice < minprice)
		{
			minprice = iprice;
		}
	}
	printf("%d\n", minprice);
	return 0;
}

