#include "stdio.h"
#include "string.h"

#define max_string_len 16
#define max_dict_size 10001
#define max_word_size 51

char dict[max_dict_size][max_string_len];
char word[max_word_size][max_string_len];
int relevent[max_dict_size];
int dict_len[max_dict_size];
int word_len[max_word_size];



bool change(char *a, char *b)
{
	int i = 0;
	int j = 0;
	bool trig = true;
	while (a[i] != 0 && b[j] != 0)
	{
		if (a[i] != b[j])
		{
			if (trig)
			{
				trig = false;
			}
			else
			{
				return false;
			}
		}
		++i;
		++j;
	}
	return true;
}

bool del(char *a, char *b)
{
	int i = 0;
	int j = 0;
	bool trig = true;
	while (a[i] != 0)
	{
		if (a[i] != b[j])
		{
			if (trig)
			{
				++i;
				trig = false;
			}
			else
			{
				return false;
			}
		}
		else
		{
			++i;
			++j;
		}
	}
	return true;
}

bool add(char *a, char *b)
{
	int i = 0;
	int j = 0;
	bool trig = true;
	while (b[j] != 0)
	{
		if (a[i] != b[j])
		{
			if (trig)
			{
				++j;
				trig = false;
			}
			else
			{
				return false;
			}
		}
		else
		{
			++i;
			++j;
		}
	}
	return true;
}

int main()
{
	int n = 0;
	while (scanf("%s", dict[n]) && dict[n][0] != '#')
	{
		dict_len[n] = strlen(dict[n]);
		++n;
	}
	int m = 0;
	while (scanf("%s", word[m]) && word[m][0] != '#')
	{
		word_len[m] = strlen(word[m]);
		++m;
	}
	for (int i = 0; i < m; i++)
	{
		int k = 0;
		bool match = false;
		for (int j = 0; j < n; j++)
		{
			if (word_len[i] == dict_len[j])
			{
				if (strcmp(word[i], dict[j]) == 0)
				{
					match = true;
					k = 1;
					relevent[0] = j;
					break;
				}
				else if (change(word[i], dict[j]))
				{
					relevent[k] = j;
					++k;
				}
			}
			else if (word_len[i] - dict_len[j] == 1)
			{
				if (del(word[i], dict[j]))
				{
					relevent[k] = j;
					++k;
				}
			}
			else if (word_len[i] - dict_len[j] == -1)
			{
				if (add(word[i], dict[j]))
				{
					relevent[k] = j;
					++k;
				}
			}
		}
		if (match)
		{
			printf("%s is correct\n", word[i]);
		}
		else
		{
			printf("%s:", word[i]);
			for (int j = 0; j < k; j++)
			{
				printf(" %s", dict[relevent[j]]);
			}
			printf("\n");

		}
	}
	return 0;
}