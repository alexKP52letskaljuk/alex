
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double calc(double, double, double);
int main() {
	double xval = 4, yval = 1, zval = 16;
	double result;
	result = calc(xval, yval, zval);
	printf("%.12lf", result);
	getchar();
	return 0;

}

// copy the code below to the answers files and add #include <math.h> at the beginning

double calc(double x, double y, double z) {
	double a;
	/* Insert your code here */
	if (x == 0 || z == 0 || x == y || x < 0 || x <= y)
		return NAN;
	else
	{
		a = (pow(x, (y + 1))) / (pow(x - y, 1 / z)) + ((2 * y) + (z / x)) + (pow(2+sin(y),cos(x)/z+abs(x-y)));
	}
	return a;
}
