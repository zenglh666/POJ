#include "stdio.h"

#define max_len 70


int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long n;
		int s_len;
		char s[max_len];
		char s_n[max_len];
		scanf("%d %s %lld", &s_len, s, &n);
		for (int i = s_len - 1; i > -1; i--)
		{
			if (n & 1)
			{
				if (s[i] == 'n')
				{
					n++;
				}
				s_n[i] = '1';
			}
			else
			{
				s_n[i] = '0';
			}
			n >>= 1;
		}
		s_n[s_len] = 0;
		if (n == 0)
		{
			printf("%s\n", s_n);
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}

