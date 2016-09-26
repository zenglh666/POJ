#include "stdio.h"
#include "string.h"
#include "ctype.h"

#define characters_num 26
#define label_num 4
#define moss_length 5
#define words_length 101

char characters[characters_num][moss_length] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
".--", "-..-", "-.--", "--.."
};
int characters_len[characters_num];
char label[label_num][moss_length] = { "..--", "---.", ".-.-", "----" };
int label_len[characters_num];

char moss2char(char moss[moss_length])
{
	for (int i = 0; i < characters_num; ++i)
	{
		if (strcmp(characters[i], moss) == 0)
		{
			return i + 'A';
		}
	}
	for (int i = 0; i < label_num; ++i)
	{
		if (strcmp(label[i], moss) == 0)
		{
			switch (i)
			{
			case 0:
				return '_';
			case 1:
				return '.';
			case 2:
				return ',';
			case 3:
				return '?';
			}
		}
	}
	return '*';
}

int char2moss(char c, char moss[moss_length])
{
	if (isupper(c))
	{
		strcpy(moss, characters[c - 'A']);
		return characters_len[c - 'A'];
	}
	else
	{
		switch (c)
		{
		case '_':
			strcpy(moss, label[0]);
			return label_len[0];
		case '.':
			strcpy(moss, label[1]);
			return label_len[1];
		case ',':
			strcpy(moss, label[2]);
			return label_len[2];
		case '?':
			strcpy(moss, label[3]);
			return label_len[3];
		}
	}
	moss[0] = 0;
	return 0;
}

void init()
{
	for (int i = 0; i < characters_num; ++i)
	{
		characters_len[i] = strlen(characters[i]);
	}
	for (int i = 0; i < label_num; ++i)
	{
		label_len[i] = strlen(label[i]);
	}
}
int main()
{
	init();
	int n;
	scanf("%d", &n);
	for (int k = 1; k <= n; ++k)
	{
		char words[words_length];
		char words_moss[words_length*moss_length];
		int words_moss_len[words_length];
		int total_len = 0;
		scanf("%s", words);
		int words_len = strlen(words);
		for (int i = 0; i < words_len; ++i)
		{
			words_moss_len[i] = char2moss(words[i], words_moss + total_len);
			total_len += words_moss_len[i];
		}
		int words_moss_len_buff[words_length];
		for (int i = 0; i < words_len; ++i)
		{
			words_moss_len_buff[words_len - 1 - i] = words_moss_len[i];
		}
		total_len = 0;
		for (int i = 0; i < words_len; ++i)
		{
			char moss_buff[moss_length];
			strncpy(moss_buff, words_moss+total_len, words_moss_len_buff[i]);
			moss_buff[words_moss_len_buff[i]] = 0;
			words[i] = moss2char(moss_buff);
			total_len += words_moss_len_buff[i];
		}
		printf("%d: %s\n", k, words);
	}
	return 0;
}

