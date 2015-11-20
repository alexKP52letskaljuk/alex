#include <stdio.h>
#include <stdlib.h>
void fillRand(int mat[4][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
           mat[i][j] = rand() % 1998-999;
        }
    }
}
void copyMatrix(int mat[4][4], int copymat[4][4])
{
    int i, j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            copymat[i][j]=mat[i][j];
        }
    }
}
void rotateCW270(int mat[4][4])
{
    int copymat[4][4];
    int i, j;
    copyMatrix(mat, copymat);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            mat[i][j]=copymat[3-j][j];

        }
        printf("\n");
    }
}
void flipH(int mat[4][4])
{
    int copymat[4][4];
    int i, j;
    copyMatrix(mat, copymat);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            mat[i][j]=copymat[i][3-j];
        }
    }
}

void transposMain(int mat[4][4])
{
    int copymat[4][4];
    int i, j;
    copyMatrix(mat, copymat);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            mat[i][j]=copymat[j][i];
        }

    }
}

 void printMatrix(int mat[4][4]) {
     int i, j;
     int n = 4;
    printf("{ ");
     for (i = 0; i < n; i++) {
         printf("{");
         for (j = 0; j < n; j++) {
            printf("%5i, ", mat[i][j]);
         }
         printf("}");
         if ( i < n - 1)
             printf("\n  ");
     }
     printf(" };\n");
 }

/*
int main()
{
    int mat[4][4];
    srand(time(NULL));
    fillRand(mat);

    printMatrix(mat);

    rotateCW270(mat);
    printMatrix(mat);

    flipH(mat);
    printMatrix(mat);

    transposMain(mat)
    printMatrix(mat);

    return 0;

}
*/
