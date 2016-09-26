#include "stdio.h"


int max(int a, int b)
{
	return a>b ? a : b;
}

int main(void)
{
	int s1, s2, s3, s4, s5, s6;
	while (scanf("%d %d %d %d %d %d", &s1, &s2, &s3, &s4, &s5, &s6) && (s1 + s2 + s3 + s4 + s5 + s6))
	{
		int BoxNum = 0;

		BoxNum += s6;

		BoxNum += s5;
		s1 = max(0, s1 - s5 * 11);

		BoxNum += s4;
		if (s2 >= s4 * 5)
			s2 -= s4 * 5;
		else
		{
			s1 = max(0, s1 - 4 * (s4 * 5 - s2));
			s2 = 0;
		}

		BoxNum += (s3 + 3) / 4;
		s3 %= 4;
		if (s3)
		{
			if (s2 >= 7 - 2 * s3)
			{
				s2 -= 7 - 2 * s3;
				s1 = max(0, s1 - (8 - s3));
			}
			else
			{
				s1 = max(0, s1 - (36 - 9 * s3 - 4 * s2));
				s2 = 0;
			}
		}

		BoxNum += (s2 + 8) / 9;
		s2 %= 9;
		if (s2)
			s1 = max(0, s1 - (36 - 4 * s2));

		BoxNum += (s1 + 35) / 36;

		printf("%d\n", BoxNum);
	}
	return 0;
}