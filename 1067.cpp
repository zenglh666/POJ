#include "stdio.h"
#include "math.h"

const double q = (1 + sqrt(5.0)) / 2.0;

int Wythoff(int a, int b)
{
	if (a > b)
	{
		int buff = a;
		a = b;
		b = buff;
	}
	int k = b - a;
	if (a == (int)(k * q))
		return 0;
	return 1;
}

int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		printf("%d\n", Wythoff(a, b));
	}
}

