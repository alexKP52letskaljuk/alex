#include <math.h>
int satisfies(int a, int b, int c) {
	int result;
	
	int modmin, sum2, max, min;
	if (a < 0 && b < 0 && c < 0)
	{
		if (a < b && a < c)
		{
			modmin = a;
			sum2 = b + c;
		}
		if (b < a&&b < c)
		{
			modmin = b;
			sum2 = a + c;
		}
		if (c < b&&c < a)
		{
			modmin = c;
			sum2 = a + b;
		}
		else
		{
			result = 0;
		}
		modmin = abs(modmin);
		if (sum2 < -256 && (modmin == 1 || modmin == 2 || modmin == 4 || modmin == 8 || modmin == 16 || modmin == 32 || modmin == 64 || modmin == 128 || modmin == 256))
		{
			result = 1;
		}

		else
		{
			if (abs(sum2)>16 || modmin > 8)
				result = 1;
		}

	}
	if (a < 0 || b < 0 || c < 0){
		if (a<0 && b >= 0 && c >= 0)
		{
			if (a>-256)
				result = 1;
		}
		if (a >= 0 && b < 0 && c >= 0)
		{
			if (b>-256)
				result = 1;
		}
		if (a >= 0 && b >= 0 && c < 0)
		{
			if (c>-256)
				result = 1;
		}


		if (a < 0 && b < 0 && c >= -256)
		{
			if ((a + b) * 4>-256)
				result = 1;
		}

		if (a < 0 && b >= 0 && c<0)
		{
			if ((a + c) * 4>-256)
				result = 1;
		}
		else
		{
			result = 0;
		}
		if (a >= 0 && b < 0 && c<0)
		{
			if ((c + b) * 4>-256)
				result = 1;

			else
				result = 0;
		}
	}
	if (a >= 0 && b >= 0 && c >= 0)
	{

		if (a > b&&a > c)
			max = a;
		if (b > a&&b > c)
			max = b;
		if (c > a&&c > b)
			max = c;
		if (a < b&&a < c)
			min = a;
		if (b < c&&b < a)
			min = b;
		if (c < a && c < b)
			min = c;
		if (max*min < 256)
			result = 1;
		else
			result = 0;
	}

	return result;
}


	