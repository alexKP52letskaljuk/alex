#include <math.h>
double calc(double x, double y, double z) {
	double a;
if (x == 0 || z == 0 || x == y || x < 0 || x <= y)
		return NAN;
	else
	{
		a = (pow(x, (y + 1))) / (pow(x - y, 1 / z)) + ((2 * y) + (z / x)) + (pow(2 + sin(y), cos(x) / z + abs(x - y)));
	}
	return a;
}
