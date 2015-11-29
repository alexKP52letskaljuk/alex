#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 void fprocess(const char * pread, const char * pwrite);
int main(){
fprocess("read.txt", "write.txt");
return 0;
}

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
 int a;
char str[100] = " ";
 for( a = 0; a < 21; a++)
 while (fgetc(read) != 10)
 ;
 int i = -1;
 while (str[i] != 10 || i == -1)
    {
        i++;
        str[i] = fgetc(read);
    }
int n = i;
for (i = 0; i < n; i++)
    if (str[i] != 'a'&& str[i] != 'A'&& str[i] != 'e'&& str[i] != 'E'&& str[i] != 'y'&& str[i] != 'Y'&& str[i] != 'u'&& str[i] != 'U'&& str[i] != 'i'&& str[i] != 'I'&& str[i] != 'o'&& str[i] != 'O')
    fputc(str[i], write);
 fclose (write);
 fclose (read);

}

