#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define max_len_r 6
#define max_len_result 150

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

int mul_r(char *a, int len_a, char *b, int len_b)
{
	int len_res = 1;
	char res[max_len_result];
	res[0] = 0;
	char res_i[max_len_result];
	for (int i = 0; i < len_a; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			res_i[j] = 0;
		}
		for (int j = 0; j < len_b; j++)
		{
			char res_i_j = a[i] * b[j] + res_i[i + j];
			res_i[i + j] = res_i_j % 10;
			res_i[i + j + 1] = res_i_j / 10;
		}
		len_res = add_r(res, len_res, res_i, i + len_b + 1);
	}
	memcpy(a, res, len_res*sizeof(char));
	return len_res;
}

int exp_r(char *r, int len_r, int n, char *res)
{
	int len_res = 1;
	res[0] = 1;
	for (int i = 0; i < n; i++)
	{
		len_res= mul_r(res, len_res, r, len_r);
	}
	return len_res;
}

int trim(char *a, int len_a,char *res)
{
	int start, end;
	for (int i = 0; i < len_a;i++)
	{
		if (a[i] != '0')
		{
			start = i;
			break;
		}
	}
	for (int i = len_a - 1; i > -1; i--)
	{
		if (a[i] != '0' && a[i] !='.')
		{
			end = i;
			break;
		}
		else if (a[i] == '.')
		{
			end = i - 1;
			break;
		}
	}
	strncpy(res, a + start, end - start + 1);
	res[end - start + 1] = 0;
	return end - start + 1;
}

int strins(char *a, int len_a, char *b, int len_b,int pos)
{
	for (int i = len_a + len_b-1; i >= pos; i--)
	{
		if (i >= pos + len_b)
		{
			a[i] = a[i - len_b];
		}
		else
		{
			a[i] = b[i - pos];
		}
	}
	return(len_a + len_b);
}

int main()
{
	char s[max_len_r];
	int n;
	while (scanf("%s%d", s, &n) == 2)
	{
		char r[max_len_r];
		int len_s = strlen(s);
		int pos_dot = len_s - 1;
		int len_r = 0;
		int k = 0;
		for (int i = len_s-1; i > -1; i--)
		{
			if (s[i] == '.')
			{
				pos_dot = i;
			}
			else
			{
				r[len_r] = s[i] - '0';
				len_r++;
			}
		}
		pos_dot = (len_s - pos_dot - 1)*n;
		char res [max_len_result];
		int len_res=exp_r(r, len_r, n, res);
		len_res=strins(res, len_res, ".", 1, pos_dot);
		char res_buff[max_len_result];
		for (int i = len_res - 1; i > -1; i--)
		{
			if (res[i] != '.')
			{
				res_buff[len_res - 1 - i] = res[i]+'0';
			}
			else
			{
				res_buff[len_res - 1 - i] = '.';
			}
		}
		len_res = trim(res_buff, len_res, res);
		printf("%s\n", res);
	}
	free(s);
	return 0;
}

