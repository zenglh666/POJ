#include"stdio.h"
#include"stdlib.h"
#include"string.h"

#define max_n 25
#define max_s 15

typedef struct order
{
	int x, y;
	int num;
	int pri;
	int next;
}order;

order ord[max_n];
int sta[max_s];
int a, b, c, ans, tot;

int cmp(const void *x, const void *y)
{
	order* i = (order *)x;
	order* j = (order *)y;
	if (i->x != j->x)
		return i->x - j->x;
	else return i->y - j->y;
}

bool check(int s)
{
	for (int i = ord[s].x; i < ord[s].y; i++)
	{
		if (sta[i] + ord[s].num > a) 
			return false;
	}
	return true;
}

void search(int s)
{
	if (s >= c && tot > ans) 
	{
		ans = tot;
	}
	else if (s < c && tot + ord[s].next > ans)
	{
		if (check(s)){
			for (int i = ord[s].x; i < ord[s].y; i++) 
				sta[i] += ord[s].num;
			tot += ord[s].pri;
			search(s + 1);
			for (int i = ord[s].x; i < ord[s].y; i++) 
				sta[i] -= ord[s].num;
			tot -= ord[s].pri;
		}
		search(s + 1);
	}
}

int main(){
	while (scanf("%d %d %d", &a, &b, &c) && (a || b || c)){
		tot = ans = 0;
		for (int i = 0; i < c; ++i)
		{
			scanf("%d %d %d", &ord[i].x, &ord[i].y, &ord[i].num);
			ord[i].pri = (ord[i].y - ord[i].x) * ord[i].num;
		}
		qsort(ord , c, sizeof(order),cmp);
		int sum = 0;
		for (int i = c-1; i > -1; --i)
		{
			sum += ord[i].pri;
			ord[i].next = sum;
		}
		search(0);
		printf("%d\n", ans);
	}
	return 0;
}

