#include <stdio.h>
#include <math.h>
int main()
{
	int t, n, i, j, arr[2];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		arr[0] = arr[1] = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &j);
			arr[i & 1] += j;
		}
		printf("%s\n", (n & 1) || abs(arr[0] - arr[1]) <= 1 ? "YES" : "NO");
	}
	return 0;
}