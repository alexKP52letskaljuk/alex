#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 int run(int moves[], int movesLen, int res[], int resLen)
 {
 	enum State { INIT = -10,
 		BREAK,
 		POP,
 		CONTINUE,
 		REPEAT,
 	};
	enum State currentState = INIT;
 	int  current_pos = 0; //radok
 	int i, j = 0, f;
 	int a[4][4] = {1, POP, 5, BREAK,
 		BREAK, 21, CONTINUE, 625,
 		BREAK, BREAK, REPEAT, POP,
 		25, 6, 7, 627};
 	int b[4][4] = {0, 1, 1, 0,
                   0, 2, 2, 3,
                   0, 0, 3, 3,
                   2, 1, 0, 3};
 	for (i = 0; i < movesLen; i++)
 	{
 		currentState = INIT;
 		switch (moves[i]) {
 				case 9: f = 0;
 				 break;
 				case 21: f = 1;
 				 break;
 				case 32: f = 2;
 				 break;
 				case 302: f = 3;
 				 break;
 				default: f = 4;
 				 currentState = BREAK;
 				 break;
 			};

            if (f != 4 && a[current_pos][f] > 0)
 		{
 			res[j] = a[current_pos][f];
 			j++;
		}
 		else
 			currentState = a[current_pos][f];

 		if (currentState == POP && j != 0)
 		{
 			j--;
 			res[j] = 0;
 		}
 		if (currentState == REPEAT)
 			i--;
 		if (currentState == BREAK)
 		{
			i = movesLen;
 			int n = j;
			for (j = n; j < resLen; j++)
 				res[j] = 0;
 			return n;
 		}
 		if (j == resLen)
 			i = movesLen;
 		current_pos = b[current_pos][f];
 	}
 	int c = j;
  	return c;

 }

int main(void)
{
int a[6] = {9, 21, 21, 32, 302, 21};
int b[6] = {-10, -10, -10, -10, -10, -10};
int d = 6, e = 6;
int c = run(a, d, b, e);
for (d = 0; d < e; d++)
		printf(" %d ", b[d]);
printf("\n %d ", c);
	return 0;
 }
