#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define max_n 51
#define max_m 101

typedef struct inversion
{
	int key;
	int inv;
}inversion;

char sequence[max_m][max_n];
inversion inv[max_m];

int inversion_count(char *seq,int n)
{
	int C, G, T;
	C = G = T = 0;
	int inv=0;
	for (int i = 0; i < n; i++)
	{
		switch (seq[i])
		{
		case 'A':
		{
			inv += C + G + T;
			break;
		}
		case 'C':
		{
			C++;
			inv += G + T;
			break;
		}
		case 'G':
		{
			G++;
			inv += T;
			break;
		}
		case 'T':
		{
			T++;
			break;
		}
		}
	}
	return inv;
}

int compare(const void* a, const void* b)
{
	inversion *x = (inversion *)a;
	inversion *y = (inversion *)b;
	return x->inv - y->inv;
}
int main()
{
	int m, n;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", sequence[i]);
		inv[i].key = i;
		inv[i].inv=inversion_count(sequence[i], strlen(sequence[i]));
	}
	qsort(inv, m, sizeof(inversion), compare);
	for (int i = 0; i < m; i++)
	{
		printf("%s\n",sequence[inv[i].key]);
	}
	return 0;
}

