

#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 
double calc(int, int);
int main()
{
	int nval = 2, mval = 2;
	double result;
	result = calc(nval, mval);
	printf("%lf", result);

}
double calc(int n, int m)

{

	double i , j;
	double a, s = 0, r = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)

		{

			a = 2 + (i / pow(2.2, j));

			s = s + a;

		}
		r = r + s;
	}
	return r;

}






