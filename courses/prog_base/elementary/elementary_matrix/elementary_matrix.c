#include <stdio.h>
#include <stdlib.h>
int main(){
srand(time(NULL));
int i, j;
int size1, size2;
int s = 0;
int trukytnuk = 0;
int sum_diagonal = 0, diagonal2 = 0;
int col = 0, row = 0;
int max = 0;
printf("vedit rozmir masuva: ");
scanf("%d", &size1);
scanf("%d", &size2);
int mat[size1][size2];
//����������� ������� ��� ����� N i M, �������� ������� N�M � ��������� �� ����������� �������. ������� �� � �������.
for(i=0;i<size1;i++)
{
    for(j=0;j<size2;j++)
        {
            mat[i][j] = rand()% 9 +1;
        }
}

for(i=0;i<size1;i++)
{
    for(j=0;j<size2;j++)
        {
           printf(" %d", mat[i][j]);
        }
        printf("\n");
}
//������ ������� N�M ��������� ����������� ������ �������. ������ � ������� ���� ��� ��������.

for(i=0;i<size1;i++)
{
    for(j=0;j<size2;j++)
        {
            s =s + mat[i][j];
        }
}
printf("\nSuma vsih elemntiv: %d", s);
//�������� N�M. ������� ���� ��� �������� ����� �������. ������� ���� ��� �������� �������� �������.
for(i = 0; i < size1; ++i)
   {
        for (j = 0; j < size2; ++j)
        {
            row =row + mat[i][j];
        }
   }
printf("\n suma elementiv radkiv: %d ", row);
  for (j = 0; j < size2; ++j)
  {
    for (i = 0; i  < size1; ++i)
     {
        col =col + mat[i][j];
     }
  }
printf("\n suma elementiv stovpziv: %d ", col);
//���������� ������� N�N. ������� ���� ������� � ������ ������ �������.
for(i=0;i<size1;i++)
{
    for(j=0;j<size2;j++)
        {
            if(i == j)
                {
                    sum_diagonal = sum_diagonal + mat[i][j];
                }
        }
        diagonal2 = diagonal2 + mat[i][size1 - i - 1];
}

printf("\n suma golovnoi diagonali: %d ", sum_diagonal);
printf("\n suma 2 diagonali: %d ", diagonal2);

//���������� ������� N�N. ������� ���� �������� �� �������� ��������� (�� ���������� �������� �������).
for(i=0;i<size1;i++)
{
    for(j=0;j<size2;j++)
        {
            if(i > j)
                trukytnuk = trukytnuk + mat[i][j];
        }

}
printf("\nsum elementiv pid golovnoy diagonaly: %d ", trukytnuk);
//������ � ������� � ������� N�M ������������ �������.
for(i=0;i<size1;i++)
{
    for(j=0;j<size2;j++)
        {
            if(mat[i][j] > max)
                max = mat[i][j];
        }

}
printf("\nmax element: %d ", max);
//������ � ������� ������� � �������� ���������� �������� ������� N�M.
int min = mat[0][0];
int index1 = 0, index2 = 0;
for(i=0;i<size1;i++)
{
    for(j=0;j<size2;j++)
        {
            if(mat[i][j] < min){
                min = mat[i][j];
                index1 = i;
                index2 = j;
             }

        }
}
printf("\nmin element: %d\n indeksu: %d, %d\n", min, index1, index2);
//�������� 2 ������� N�M. ����� � ��� ��������� ���������� �����.
// ϳ��� ����� ��������� �������� ����� ������� � ����� �������. ������� ����� ������� � �������.
int mat2[size1][size2];
printf("Skopiyovana matruza: \n");
for(i=0;i<size1;i++)
{
    for(j=0;j<size2;j++)
        {
            mat2[i][j] = mat[i][j];
            printf("%d ", mat2[i][j]);
        }
printf("\n");
}

return 0;
}
