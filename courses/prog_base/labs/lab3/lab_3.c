#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
void nullMatrix(size_t row, size_t col, int mat[row][col]);
void printArr(HANDLE hConsole, size_t row, size_t col, int mat[row][col]);
void fillRand(size_t row, size_t col, int mat[row][col], int min, int max);
int changeElem(size_t row, size_t col, int mat[row][col], unsigned rower, unsigned colone, int elem);
void flipH(size_t row, size_t col, int mat[row][col]);
float SerZnach(size_t row, size_t col, int mat[row][col]);
long long sumCol (size_t row, size_t col, int mat[row][col], unsigned colen, int * status);
void moveMaxFirstToMinLast (size_t row, size_t col, int mat[row][col]);
void moveMaxToMinLast (size_t row, size_t col, int mat[row][col]);
void moveMaxColToMin (size_t row, size_t col, int mat[row][col]);
void func(int a, size_t row, size_t col, int mat[row][col], HANDLE hConsole);
int main (void)
 {
 	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned)time(NULL));
 	char ch;
 	int i;
 	size_t row;
 	size_t col;
 	char str[20];
    int kek;
 	char Interface[9][80] = {"1. Obnylutu vsi elementu - null",
 		"2. Zapovnutu randomno matrix v vedenom diapazoni - fill rand",
 		"3. Zminutu element masuvy za vkazanumu indexamu - change element",
 		"4. Vidobrazutu gorizontalno - flipH",
 		"5. Seredne arufmetuchne matrix - seredne arufmetuchne",
 		"6. Sum elementiv vedenogo stovpza - col sum",
		"7. Change the first min and last max matrix elements in places - min1 na max2",
 		"8. Change the last mini and last max matrix elements in places - min2 na max2",
        "9. Change col with mas sum and with min sum - col2 na col1"
 		};

 	printf("\nenter array row, less then 10 \n");
 	int status = 0;
 	status = scanf("%u", &row);
 	if ( status == 0 || row > 9)
 	{
 		printf("you enter wrong value\n");
 		return -1;
 	}
 	printf("\nenter array col, less then 10 \n");
 	status = scanf("%u", &col);
 	if ( status == 0 || col > 9)
 	{
 		printf("you enter wrong value\n");
 		return -1;
 	}
	COORD pos;
 	int mat[row][col];
 	nullMatrix(row, col, mat);
     	while (1)
    {
	printArr(hConsole, row, col, mat);
	fflush(stdin);
	gets(str);
 	if (strcmp(str, "null") == 0)
    kek = 0;
   else if (strcmp(str, "fill rand") == 0)
    kek = 1;
  else  if (strcmp(str, "change element") == 0)
    kek = 2;
  else  if (strcmp(str, "flipH") == 0)
    kek = 3;
  else  if (strcmp(str, "seredne arufmetuchne") == 0)
    kek = 4;
  else  if (strcmp(str, "col sum") == 0)
    kek = 5;
  else if (strcmp(str, "min1 na max2") == 0)
    kek = 6;
   else if (strcmp(str, "min2 na max2") == 0)
    kek = 7;
   else if (strcmp(str, "col2 na col1") == 0)
    kek = 8;
    else if (strcmp(str, "help") == 0){
            kek = 555;
        for (i = 0; i < 9; i++)
            puts(Interface[i]);
    }
    else
        kek = 54436;
Beep(400, 300);
func(kek, row, col, mat, hConsole);
 	puts(" ");
 	str[0] = '\0';
    getchar();
    }
 	return EXIT_SUCCESS;
}
 void func(int a, size_t row, size_t col, int mat[row][col], HANDLE hConsole)
 {
 	COORD pos;
 	pos.X = 0;
 	pos.Y = 18;
	int status = 1;
	SetConsoleCursorPosition(hConsole, pos);
    float e = SerZnach(row, col, mat);
 	switch (a)
 	{
 		case 0: nullMatrix(row, col, mat); break;
 		case 1:	printf("Enter min and max random value\nless than 10000\n");
 			int min, max;
 			printf("min = ");
 			status = 1;
 			status = scanf("%i", &min);
 			if(status == 0)
 			{
 				printf("error");
				fflush(stdin);
 				break;
			}
 			printf("max = ");
			status = 1;
 			status = scanf("%u", &max);
 			if(status == 0)
 			{
 				printf("error");
 				fflush(stdin);
 				break;
 			}
 			if (min > 9999 || max > 9999 || min < -9999 || max < -9999)
 			{
 				printf("error");
 				break;
 			}
 			fillRand(row, col, mat, min, max); break;
 		case 2: printf("Enter position of element\n you want change\nrow = ");
 			unsigned rower, colen;
 			int elem;
 			status = 1;
 			status = scanf("%u", &rower);
			if(status == 0)
 			{
 				printf("error");
				fflush(stdin);
 				break;
 			}
			printf("colone = ");
 			status = 1;
 			status = scanf("%u", &colen);
 			if(status == 0)
 			{
 				printf("error");
 				fflush(stdin);
				break;
 			}
 			printf("new value, less then 10000 = ");
 			status = 1;
 			status = scanf("%u", &elem);
 			if(status == 0)
		{
 				printf("error");
				fflush(stdin);
 				break;
 			}
			if (elem > 9999)
 			{
 				printf("error");
 				break;
 			}
 			if (changeElem(row, col, mat, rower - 1, colen - 1, elem) == 0)
 				printf("error");
 			break;
		case 3: flipH(row, col, mat); break;
 		case 4:
            printf("Seredne arufmetuchne: %f ", e);
             break;
 		case 5: printf("Enter number of the line\n");
 			unsigned col1;
			status = 1;
 			status = scanf("%u", &col1);
 			if(0 == status)
 			{
 				printf("error");
 				fflush(stdin);
 				break;
 			}
 			long long sum = sumCol (row, col, mat, colen, &status);
 			if (status == 0)
 				printf("ERROR");
			else
 				printf("Sum of elements of %u line \n%lld", col1, sum);
 				 break;
 		case 6: moveMaxFirstToMinLast (row, col, mat); break;
 		case 7: moveMaxToMinLast (row, col, mat); break;
		case 8: moveMaxColToMin (row, col, mat); break;

	}
 }
void printArr(HANDLE hConsole, size_t row, size_t col, int mat[row][col])
{
    int i, j;
    system("cls");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%i ", mat[i][j]);
        }
        puts("");
    }
}

void nullMatrix(size_t row, size_t col, int mat[row][col])
 {
 	unsigned i, j;
	for (i = 0; i < row; i++)
 		for (j = 0; j < col; j++)
 			mat[i][j] = 0;
 }


void fillRand(size_t row, size_t col, int mat[row][col], int min, int max)
 {
 	unsigned i, j;
 	if (min > max)
 	{
 		int temp = max;
 		max = min;
 		min = temp;
 	}
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			mat[i][j] = rand() % (max - min + 1) + min;
 }

int changeElem(size_t row, size_t col, int mat[row][col], unsigned rown, unsigned colone, int elem)
 {
if(row <= rown || col <= colone)
 		return 0;
 	mat[rown][colone] = elem;
 	return 1;
}

void flipH(size_t row, size_t col, int mat[row][col])
 {
 	int c;
 	unsigned i, j;
 	for (i = 0; i < (row + 1) / 2; i++)
	for (j = 0; j < col; j++)
 		{
			c = mat[i][j];
    mat[i][j] = mat[row - 1 - i][j];
 			mat[col - 1 - i][j] = c;
 		}
 }

float SerZnach(size_t row, size_t col, int mat[row][col])
{
    int i, j;
   float a = 0;
    float serznach = 0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            a = a + mat[i][j];
        }
    }
    serznach = a/(row * col);
    return serznach;
}

long long sumCol (size_t row, size_t col, int mat[row][col], unsigned colen, int * status)
{
 	if (colen > col - 1)
{
 		*status = 0;
 		return 0;
 	}
	*status = 1;
	long long sum = 0;
 	unsigned i;
 	for (i = 0; i < colen; i++)
		sum += mat[colen][i];
 	return sum;
 }


void moveMaxFirstToMinLast (size_t row, size_t col, int mat[row][col])
 {
 	unsigned i, j, rowMax = 0, rowMin = 0, colMax = 0, colMin = 0;
	int min = mat[0][0], max = mat[0][0], temp;
	for (i = 0; i < row; i++)
 		for (j = 0; j < col; j++)
		{
	if (min > mat[i][j])
	{
 				colMin = j;
 				rowMin = i;
 				min = mat[i][j];
 			}
 			if (max <= mat[i][j])
 			{
 				colMax = j;
				rowMax = i;
 				max = mat[i][j];
 			}
	}
 	temp = mat[rowMin][colMin];
 	mat[rowMin][colMin] = mat[rowMax][colMax];
	mat[rowMax][colMax] = temp;
 }

 void moveMaxToMinLast (size_t row, size_t col, int mat[row][col])
{
unsigned i, j, rowMax = 0, rowMin = 0, colMax = 0, colMin = 0;
	int min = mat[0][0], max = mat[0][0], temp;
 	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
 		{
			if (min >= mat[i][j])
 			{
				colMin = j;
			rowMin = i;
				min = mat[i][j];
 			}
 			if (max <= mat[i][j])
 			{
 				colMax = j;
 				rowMax = i;
			max = mat[i][j];
 			}
 		}
 	temp = mat[rowMin][colMin];
 	mat[rowMin][colMin] = mat[rowMax][colMax];
 	mat[rowMax][colMax] = temp;
}


void moveMaxColToMin (size_t row, size_t col, int mat[row][col])
 {
unsigned i, colMax = 0, colMin = 0;
 	int temp;
 	int colen;
 	int status = 0;
 	int sum, sumMax = sumCol(row, col, mat, colen, &status), sumMin = sumCol(row, col, mat, colen, &status);
	for (i = 0; i < col; i++)
	{
	sum = sumCol(row, col, mat, colen, &status);
 		if (sum < sumMin)
		{
 			sumMin = sum;
 			colMin = i;
		}
 		if (sum > sumMax)
		{
			sumMax = sum;
		colMax = i;
		}
	}
	for (i = 0; i < col; i++)
{
 		temp = mat[colMin][i];
	mat[colMin][i] = mat[colMax][i];
mat[colMax][i] = temp;
}
}
