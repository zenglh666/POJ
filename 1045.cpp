#include "stdio.h"
#include "math.h"
int n;
double vs, r, c, w;

int main()
{
	scanf("%lf%lf%lf%d", &vs, &r, &c, &n);
	while (n--)
	{
		scanf("%lf", &w);
		printf("%.3f\n", r * c * w * vs * sqrt(1 / (r*r*c*c*w*w + 1)));
	}
	return 0;
}
