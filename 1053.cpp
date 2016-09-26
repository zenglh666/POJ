#include "stdio.h"

#define max_cards_count 12
#define character_num 5

char cards[max_cards_count][character_num];

bool check(int i, int j, int k)
{
	bool isset = true;
	for (int u = 0; u < character_num-1; ++u)
	{
		if (!((cards[i][u] == cards[j][u] && cards[i][u] == cards[k][u])
			|| (cards[i][u] != cards[j][u] && cards[i][u] != cards[k][u]
			&& cards[j][u] != cards[k][u])))
		{
			isset = false;
			break;
		}
	}
	return isset;
}
int main()
{
	while (scanf("%s", cards[0])==1)
	{
		for (int i = 1; i < max_cards_count; ++i)
		{
			scanf("%s", cards[i]);
		}
		printf("CARDS: ");
		for (int i = 0; i < max_cards_count; ++i)
		{
			printf(" %s", cards[i]);
		}
		putchar('\n');
		int count = 1;
		for (int i = 0; i < max_cards_count; ++i)
		{
			for (int j = i + 1; j < max_cards_count; ++j)
			{
				for (int k = j + 1; k < max_cards_count; ++k)
				{
					if (check(i, j, k))
					{
						if (count == 1)
						{
							printf("SETS:   %d.  %s %s %s\n", count, cards[i], cards[j], cards[k]);
						}
						else
						{
							printf("        %d.  %s %s %s\n", count, cards[i], cards[j], cards[k]);
						}
						++count;
					}
				}
			}
		}
		if (count == 1)
		{
			printf("SETS:   *** None Found ***\n");
		}
		putchar('\n');
	}
	return 0;
}