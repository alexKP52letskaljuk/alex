#include <stdio.h>
#include <stdlib.h>
int main() {
  char str[1000];
  int i = 0;
  printf("Vedit stroky ");
  gets(str);
  while (str[i] == ' ')
    i++;
  if (str[i] != '_' && !((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
    printf("Error: %c", str[i]);
    return 1;
  }

  while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '1' && str[i] <= '9') || (str[i] == '_'))
    i++;
  while (str[i] != '\0') {
    if (str[i] != ' ') {
      printf("Error");
      return 1;
    }
    i++;
  }
  printf("String includes valid idintificator");
  return 0;
}
