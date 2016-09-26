#include "stdio.h"
#include "math.h"


int main(void)
{
	int cases;
	scanf("%d", &cases);
	for (int c = 1; c <= cases; c++)
	{
		char left[3][6], right[3][6], status[3][6];

		int time['L' + 1] = { 0 };
		bool zero['L' + 1] = { false };

		for (int k = 0; k < 3; k++)
			scanf("%s %s %s", left[k], right[k], status[k]);

		for (int i = 0; i<3; i++)
		{
			switch (status[i][0])
			{
			case 'u':
			{
				for (int j = 0; left[i][j]; j++)
				{
					time[left[i][j]]++; 
					time[right[i][j]]--;
				}
				break;
			}
			case 'd':
			{
				for (int j = 0; left[i][j]; j++)
				{
					time[left[i][j]]--;
					time[right[i][j]]++;
				}
				break;
			}
			case 'e':
			{
				for (int j = 0; left[i][j]; j++)
				{
					zero[left[i][j]] = true;
					zero[right[i][j]] = true;  
				}
				break;
			}
			}
		}

		int max = -1;
		char alpha;
		for (int j = 'A'; j <= 'L'; j++)
		{
			if (zero[j])
				continue;

			if (max <= abs(time[j]))
			{
				max = abs(time[j]);
				alpha = j;
			}
		}

		if (time[alpha]>0)
			printf("%c is the counterfeit coin and it is heavy.\n", alpha);
		else
			printf("%c is the counterfeit coin and it is light.\n", alpha);
	}
	return 0;
}
