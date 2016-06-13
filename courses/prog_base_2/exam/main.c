#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check (char* str)
{
 int opened = 0;
 int closed = 0;

int len = strlen (str);

for (int i = 0; i < len; i++)
 {
 if ( str[i] == '(' )
 opened++;
 else if ( str[i] == ')' )
 closed++;
 else if ( str[i] != ' ' && str[i] != '\t' )
 return 0;

 if (closed > opened)
 return 0;
 }
 if (closed == opened)
 return 1;
 else
 return 0;
}

int main()
{
 char* str1 = " ( ( ( ( ) ) ) )";
 char* str2 = " ( ( ) ( ) ))";
 printf ("check1: %d\n", check (str1));
 printf ("check2: %d\n", check (str2));
}
