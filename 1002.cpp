#include "stdio.h"
#include "string.h"
#include "ctype.h"

#define max_number 10000000
#define max_len_s 128

int c2n[] =
{
	2, 2, 2,
	3, 3, 3,
	4, 4, 4,
	5, 5, 5,
	6, 6, 6,
	7, 0, 7, 7,
	8, 8, 8,
	9, 9, 9
};

int directory[max_number] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char s[max_len_s];
		scanf("%s", &s);
		int c = 0;
		for (int j = 0; s[j]; j++)
		{
			if (isdigit(s[j]))
			{
				c = c * 10 + s[j] - '0';
			}
			else if (isalpha(s[j]))
			{
				c = c * 10 + c2n[s[j] - 'A'];
			}	
		}
		directory[c]++;
	}
	bool flag = false;
	for (int j = 0; j < max_number; j++)
	{
		if (directory[j] > 1)
		{
			flag = true;
			char s[max_len_s];
			printf("%03d-%04d %d\n", j/10000,j%10000,directory[j]);
		}
	}
	if (!flag)
	{
		puts("No duplicates.");
	}
	return 0;
}

