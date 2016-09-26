#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char *Haab[] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac",
"ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
char *Tzolkin[] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
"chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };

struct result
{
	char s[24];
	struct result *next;
};
 
int searchStr(char *list[], int n, char *str)
{
	int i;
	for (i = 0; i<n; i++)
	{
		if (strcmp(list[i], str) == 0)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int day, month, year, date, n, i;
	char s[24];
	struct result *head = NULL, *p;
	struct result *tail = NULL;

	scanf("%d", &n);

	for (i = 0; i<n; i++)
	{
		scanf("%d. %s %d", &day, s, &year);

		month = searchStr(Haab, 19, s);
		date = year * 365 + month * 20 + day;

		year = date / 260;
		date = date % 260;
		day = date % 13 + 1;
		month = date % 20;
  
		if (head == NULL)
		{
			head = tail = (struct result *)malloc(sizeof(struct result));
			tail->next = NULL;
		}
		else
		{
			tail->next = (struct result *)malloc(sizeof(struct result));
			tail = tail->next;
			tail->next = NULL;
		}
		sprintf(tail->s, "%d %s %d", day, Tzolkin[month], year);
	}
 
	printf("%d\n", n);
	p = head;
	while (p != NULL)
	{
		printf("%s\n", p->s);
		p = p->next;
	}


	return 0;
}

