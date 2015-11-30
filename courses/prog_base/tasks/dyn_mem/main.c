#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main( void )
{
	char * str = NULL;
	str = malloc(sizeof(char) * 100);
	if (NULL == str)
		return 1;
	puts("enter your string");
	unsigned * i = NULL;
	i = malloc(sizeof(int) * 1);
	if (NULL == i)
		return 1;
	unsigned * j = NULL;
	j = malloc(sizeof(int) * 1);
	if (NULL == j)
		return 1;
	gets(str);
    *i = 0;
	while ( *i < strlen(str) )
    {
        *j = *i + 1;
		while ( *j < strlen(str) )
        {
			if (*(str + *i) == *(str + *j))
			{
				printf("%c", *(str + *i));
				free(i);
				free(j);
				free(str);
				return 0;
			}
			*j = *j + 1;
        }
        *i = *i + 1;
    }
	printf("0");
	free(i);
	free(j);
	free(str);
	return 0;
}
