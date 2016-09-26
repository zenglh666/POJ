#include "stdio.h"
#include "stdlib.h"

#define size 1000
#define adj 9

int width; 
int total = 0;  

typedef struct Pix
{
	int pos;  
	int code;  
}Pix;

typedef struct Pair
{
	int code;
	int count;
}Pair;
Pair InMapPair[size];
Pix OutMap[size * 2*adj];  

int cmp(const void* a, const void* b)
{
	Pix* x = (Pix*)a;
	Pix* y = (Pix*)b;
	return x->pos - y->pos;
}

int GetValue(int pos)
{
	int i = 0, p = 0;
	while (p < pos + 1){
		p += InMapPair[i].count;
		i++;
	}
	return InMapPair[i - 1].code;
}
int GetCode(int pos)
{
	int code = GetValue(pos);
	int MaxAbs = 0;

	int row = pos  / width;
	int col = pos  % width;

	for (int i = row - 1; i <= row + 1; i++)
		for (int j = col - 1; j <= col + 1; j++)
		{
			int tpos = i*width + j;

			if (i >= 0 && j >= 0 && j < width && tpos < total && tpos != pos)
			{
				int tcode = GetValue(tpos);

				if (MaxAbs<abs(tcode - code))
					MaxAbs = abs(tcode - code);
			}
		}
	return MaxAbs;
}

int edge(int pos,int k)
{
	int row = pos / width;
	int col = pos % width;

	for (int i = row - 1; i <= row + 1; i++){
		for (int j = col - 1; j <= col + 1; j++)
		{
			int tpos = i*width + j;

			if (i >= 0 && j >= 0 && j < width && tpos < total)
			{
				OutMap[k].pos = tpos;
				OutMap[k].code = GetCode(tpos);
				k++;
			}
		}
	}
	return k;
}

int main()
{
	while (scanf("%d" ,& width) && width)
	{
		int pairv, pairt;
		int k = 0;
		total = 0;
		while (scanf("%d %d", &pairv ,&pairt )&& pairt)
		{
			InMapPair[k].code = pairv;
			InMapPair[k].count = pairt;
			k++;
			total += pairt;
		}
		int PairNum = k;

		int pos = 0;  
		k = 0; 
		for (int p = 0; p <= PairNum; p++)
		{
			k=edge(pos, k);
			if ((pos / width + 1)*width < total)
			{
				k=edge((pos / width + 1)*width, k);
			}
			pos += InMapPair[p].count;
		}
		qsort(OutMap, k, sizeof(Pix), cmp);
		printf("%d\n", width);
		Pix temp = OutMap[0];
		for (int i = 0; i<k; i++)
		{
			if (temp.code != OutMap[i].code)
			{
				printf("%d %d\n", temp.code, OutMap[i].pos - temp.pos);
				temp = OutMap[i];
			}
		}
		printf("%d %d\n", temp.code, total - temp.pos);
		printf("0 0\n");

	}
	printf("0\n");
	return 0;
}



