#include "stdio.h"
#include "string.h"

#define max_len_result 70

int add_r(char *a, int len_a, char *b, int len_b)
{
	if (len_a >= len_b)
	{
		char car = 0;
		for (int i = 0; i < len_b; i++)
		{
			char res_i_j = a[i] + b[i] + car;
			a[i] = res_i_j % 10;
			car = res_i_j / 10;
		}
		for (int i = len_b; i < len_a; i++)
		{
			char res_i_j = a[i] + car;
			a[i] = res_i_j % 10;
			car = res_i_j / 10;
		}
		if (car > 0)
		{
			a[len_a] = car;
			return len_a + 1;
		}
		else
		{
			return len_a;
		}
	}
	else
	{
		char car = 0;
		for (int i = 0; i < len_a; i++)
		{
			char res_i_j = a[i] + b[i] + car;
			a[i] = res_i_j % 10;
			car = res_i_j / 10;
		}
		for (int i = len_a; i < len_b; i++)
		{
			char res_i_j = b[i] + car;
			a[i] = res_i_j % 10;
			car = res_i_j / 10;
		}
		if (car > 0)
		{
			a[len_b] = car;
			return len_b + 1;
		}
		else
		{
			return len_b;
		}
	}
}

bool check(char *a, char *b, int len)
{
	for (int i = len-1; i >-1; --i)
	{
		if (b[i] == a[len-1])
		{
			bool cir = true;
			for (int j = len - 1, k = i; j > -1; --j, --k)
			{
				if (a[j] != b[(k + len) % len])
				{
					cir = false;
					break;
				}
			}
			if (cir)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	char number[max_len_result];
	while (gets(number))
	{
		char buff[max_len_result];
		int len = strlen(number);
		for (int i = len - 1; i > -1; --i)
		{
			buff[i] = number[len - 1 - i]-'0';
		}
		char number_buff[max_len_result];
		memcpy(number_buff, buff, len*sizeof(char));
		bool right = true;
		for (int i = 2; i <= len; ++i)
		{
			int len_out = add_r(buff, len, number_buff, len);
			if (len_out > len)
			{
				right = false;
				break;
			}
			else
			{
				if (!check(buff, number_buff, len))
				{
					right = false;
					break;
				}
			}
		}

		if (right)
		{
			printf("%s is cyclic\n", number);
		}
		else
		{
			printf("%s is not cyclic\n", number);
		}
	}
	return 0;
}

