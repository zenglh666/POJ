#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define max_grp 31269

unsigned int grp_len[max_grp+1];
unsigned int grp_fore_len[max_grp+1];

void setup()
{
	grp_len[0] = 0;
	grp_len[1] = 1;
	grp_fore_len[0] = 0;
	grp_fore_len[1] = 1;
	for (int i = 2; i <= max_grp; i++)
	{
		grp_len[i] = grp_len[i - 1] + (int)log10((double)i) + 1;
		grp_fore_len[i] = grp_fore_len[i - 1] + grp_len[i];
	}
}

int getpos(int pos)
{
	int grp;
	for (int i = 1; i < max_grp; i++)
	{
		if (pos <= grp_fore_len[i])
		{
			grp = i;
			break;
		}
	}
	pos -= grp_fore_len[grp - 1];
	int len = 0;
	int num;
	for (int i = 1; i <= grp; i++)
	{
		len += (int)log10((double)i) + 1;
		if (len >= pos)
		{
			num = i;
			break;
		}
	}
	int digit = (num / ((int)pow(10.0, len - pos))) % 10;
	return digit;
}
int main()
{
	int t;
	scanf("%d", &t);
	setup();
	for (int i = 0; i < t; i++)
	{
		int pos;
		scanf("%d", &pos);
		int digit= getpos(pos);
		printf("%d\n", digit);
	}
	return 0;
}

