
#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
double k, h, x[101], y[101];

double angle(double x0, double y0, double x1, double y1) {
	double a = atan2(y0, x0);
	double b = atan2(y1, x1);
	if (a - b < -M_PI) a += 2 * M_PI;
	if (a - b > M_PI) a -= 2 * M_PI;
	return a - b;
}

int main(void) {
	int i, n;
	scanf("%lf %lf %d", &k, &h, &n);
	for (i = 0; i<n; i++)
		scanf("%lf %lf", &x[i], &y[i]);
	x[n] = x[0], y[n] = y[0];

	double min = 0, max = 0, sum = 0;
	for (i = 0; i < n; i++) {
		double temp = angle(x[i], y[i], x[i + 1], y[i + 1]);
		sum += temp;
		if (sum<min) min = sum;
		if (sum>max) max = sum;
		if (max - min >= 2 * M_PI) {
			max = min + 2 * M_PI;
			break;
		}
	}
	printf("%.2lf\n", k*h*(max - min));
	return 0;
}