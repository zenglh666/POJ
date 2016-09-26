#include "stdio.h"
#include "string.h"

#define max_sequence_length 21

int P_sequence[max_sequence_length];
int parenthesis[max_sequence_length*2];
int count[max_sequence_length];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		P_sequence[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &P_sequence[i]);
		}
		int k = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = P_sequence[i - 1]; j < P_sequence[i]; ++j)
			{
				parenthesis[k] = 0;
				++k;
			}
			parenthesis[k] = 1;
			++k;
		}
		int depth = 1;
		memset(count, 0, sizeof(count));
		for (int i = 1; i < k; ++i)
		{
			if (parenthesis[i] == 0)
			{
				count[depth]++;
				++depth;
			}
			else
			{
				depth--;
				printf("%d ", count[depth]);
				count[depth-1] += count[depth];
				count[depth] = 0;
			}
		}
		putchar('\n');
	}
	return 0;
}

