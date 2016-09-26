#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define max_kind 26
#define max_need_kind 4

int stamp[max_kind];
int stamp_count[max_kind];
int kind;
int best[max_need_kind];
int best_kind;
int best_num;
int trace[max_need_kind];
bool flag_tie;

int compare(const void *a, const void *b)
{
	int *x = (int *)a;
	int *y = (int *)b;
	return *x - *y;
}

void trim()
{
	int i = 0;
	int j = 0;
	int last_stamp = 0;
	int last_count = 0;
	while (i < kind)
	{
		if (stamp[i] == last_stamp)
		{
			if (last_count <= max_need_kind)
			{
				stamp[j] = stamp[i];
				j++;
			}
			last_count++;
			i++;
		}
		else
		{
			last_count = 0;
			last_stamp = stamp[i];
		}
	}
	kind = j;
}

void update_best(int trace_kind,int trace_num)
{
	flag_tie = false;
	memcpy(best, trace, sizeof(best));
	best_kind = trace_kind;
	best_num = trace_num;
}
void dfs(int need, int pos, int trace_num, int trace_kind)
{
	if (need == 0)
	{
		if (trace_kind > best_kind)
		{
			update_best(trace_kind, trace_num);
		}
		else if (trace_kind == best_kind)
		{
			if (trace_num < best_num)
			{
				update_best(trace_kind, trace_num);
			}
			else if (trace_num == best_num)
			{
				if (trace[trace_num-1 ] > best[best_num-1 ])
				{
					update_best(trace_kind, trace_num);
				}
				else if (trace[trace_num -1] == best[best_num-1 ])
				{
					flag_tie = true;
				}
			}
		}
		return;
	}
	if (trace_num < max_need_kind)
	{
		for (int i = pos; i < kind; i++)
		{
			if (need >= stamp[i])
			{
				stamp_count[i]++;
				trace[trace_num] = stamp[i];
				if (stamp_count[i] > 1)
				{
					dfs(need - stamp[i], i, trace_num + 1, trace_kind);
				}
				else
				{
					dfs(need - stamp[i], i, trace_num + 1, trace_kind + 1);
				}
				trace[trace_num] = 0;
				stamp_count[i]--;
			}
			else
			{
				return;
			}
		}
	}
	return;
}

int main()
{
	kind = 0;
	while (scanf("%d", &stamp[kind])==1)
	{
		if (stamp[kind] != 0)
		{
			kind++;
		}
		else
		{
			qsort(stamp, kind, sizeof(int), compare);
			trim();
			int need;
			while (scanf("%d", &need) == 1 && need)
			{
				best_kind = 0;
				best_num = 0;
				memset(best, 0, sizeof(best));
				memset(stamp_count, 0, sizeof(stamp_count));
				memset(trace, 0, sizeof(trace));
				flag_tie = false;
				dfs(need, 0, 0, 0);
				if (flag_tie)
				{
					printf("%d (%d): tie\n", need, best_kind);
				}
				else if (best_kind == 0)
				{
					printf("%d ---- none\n", need);
				}
				else
				{
					printf("%d (%d):", need, best_kind);
					for (int i = 0; i < best_num; i++)
					{
						printf(" %d", best[i]);
					}
					printf("\n");
				}
			}
			kind = 0;
		}
	}
	return 0;
}