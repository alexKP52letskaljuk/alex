#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bloc(char* c, char* kek);

int main(int argc, char** args)
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

    char* kek[50][4];
    char* c[50];
    printf("vedit stroky: \n");
    gets(* c);
    bloc(* c, * kek);

    fclose (write);
 fclose (read);
    return 0;
}
int bloc(char* c, char* kek)
{
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


*/
