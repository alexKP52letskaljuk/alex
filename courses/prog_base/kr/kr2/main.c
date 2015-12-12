#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bloc(char* c, char* kek);

int main()
{
    char* kek[50][4];
    char* c[50];
    printf("vedit stroky: \n");
    gets(* c);
    bloc(* c, * kek);

    return 0;
}
int bloc(char* c, char* kek)
{
    int i;
    int j;

    for(i=0;i<strlen(c);i++)
        *(kek + i) = c[i];
    for(i=0;i<strlen(c)/4;i++){
        for(j=0;j<4;j++)
        putchar(kek[i][j]);
        puts("");
    }
    return 0;
}/*
void fprocess(const char * pread, const char * pwrite)
{
 FILE * read = NULL;
 FILE * write = NULL;
 read = fopen(pread, "r");
 write = fopen(pwrite, "w");
 if (read == NULL )
 return;
 if( write == NULL)
    return;
        int i;
    int j;
    char b[5];
    float a = strlen(c)/4;
    for(i=0;i<a;i++)
    {
        for(j=0;j<4;j++){
        b[j] = strlen(c) - (a*4);
        a--;
        kek[j] = b[j];
    }
    }
    return 0;
*/
