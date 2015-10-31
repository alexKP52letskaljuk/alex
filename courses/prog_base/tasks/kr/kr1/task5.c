#include <stdio.h>
#include <stdlib.h>
main()
{
	int i, result;
	int arr[6] = { 1, 2, 3, 7, 0, 15};
	for (i = 0; i < 5; i++)
	{
		result = arr[i] - arr[i+1];
		printf("%i ", result);
	}
	getchar();
	return i;
}