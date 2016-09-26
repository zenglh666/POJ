#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define max_digit_len 80
#define max_iter 15

char digits[max_iter+1][max_digit_len+1];

void R(int n)
{
	int count[10] = { 0 };
	for (int i = 0; i < strlen(digits[n]); i++)
	{
		count[digits[n][i] - '0']++;
	}
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		if (count[i] > 0)
		{
			if (count[i] < 10)
			{
				digits[n + 1][j] = count[i] + '0';
				j++;
			}
			else
			{
				digits[n + 1][j] = count[i]/10 + '0';
				j++;
				digits[n + 1][j] = count[i]%10 + '0';
				j++;
			}
			digits[n + 1][j] = i + '0';
			j++;
		}
	}
	digits[n + 1][j] = 0;
}

int self_after()
{
	for (int i = 0; i < max_iter; i++)
	{
		if (strcmp(digits[i], digits[i + 1])==0)
		{
			return i;
		}
	}
	return -1;
}

int invent_loop()
{
	for (int i = 2; i <= max_iter; i++)
	{
		for (int j = 0; j <= i - 2; j++)
		{
			if (strcmp(digits[i], digits[j])==0)
			{
				return i - j;
			}
		}
	}
	return -1;
}

int main()
{
	while (scanf("%s", digits[0]) && digits[0][0] != '-')
	{
		for (int i = 0; i < max_iter; i++)
		{
			R(i);
		}
		int self_after_k = self_after();
		if (self_after_k>=0)
		{
			if (self_after_k == 0)
			{
				printf("%s is self-inventorying\n", digits[0]);
			}
			else
			{
				printf("%s is self-inventorying after %d steps\n", digits[0], self_after_k);
			}
		}
		else
		{
			int invent_loop_k = invent_loop();
			if (invent_loop_k > 1)
			{
				printf("%s enters an inventory loop of length %d\n", digits[0], invent_loop_k);
			}
			else
			{
				printf("%s can not be classified after 15 iterations\n", digits[0]);
			}
		}
	}
	return 0;
}