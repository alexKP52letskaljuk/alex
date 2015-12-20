#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 int main(void)
 {
//Зчитати символ від користувача і записати у змінну, вивести цей символ підряд N раз підряд у консолі.
char sumbol;
int number;
int i = 0;
int a;
printf("vedit sumvol ");
scanf("%c", &sumbol);
printf("vedit kilkist raziv vuvedenna sumvoly: ");
scanf("%d", &number);

for(i=0;i<number;i++)
{
    printf("%c", sumbol);
}
//Визначити чи символ є цифрою і вивести результат (1 - так, 0 - ні).
if(sumbol>=48&&sumbol<=57 )
    printf("\n1");
else
    printf("\n0");
//•Визначити чи символ є буквою і вивести результат.
if((sumbol>=65&&sumbol<=90)||(sumbol>=97&&sumbol<=122))
printf("\nsumvol - bukva");
if(sumbol>=48&&sumbol<=57 )
printf("\nsumvol - zufra");
//•Якщо символ у верхньому регістрі вивести 2, якщо у нижньому 1, якщо не буква - вивести 0.
if(sumbol>=65&&sumbol<=90)
   {
         printf("\nVerhniy registr: 2");
     }
    else
        if(sumbol>=97&&sumbol<=122 )
     {
       printf("\nNugniy registr: 1");
}
else
    {
        printf("\nSumvol ne bykva: 0");
     }

//•Визначити чи є символ пустим (недрукованим) і вивести результат.
if(sumbol>=0&&sumbol<=32)
   {
         printf("\nSumvol ne drykovanuy abo pystuy");
     }
else
    printf("\n%c ", sumbol);
//•Створити одномірний масив символів і заповнити його символами, які вводить користувач.
fflush(stdin);
char str[100];
printf("\nVedit sumvolu: ");
gets(str);
char str1[100];
for(i=0;i<strlen(str);i++)
{
    str1[i] = str[i];
}
//•Замінити всі цифрові символи у масиві символів на пробіли, вивести елементи масиву символів через кому.
for(i=0;i<strlen(str);i++){
    if(str[i]>=48&&str[i]<=57)
 {
    str[i] = ' ';
 }
 printf("%c", str[i]);
}
printf("\n");
for(i=0;i<strlen(str);i++){
printf("%c,", str[i]);
}

//•У масиві символів замінити всі букви у нижньому регістрі у верхній регістр,
// а всі цифрові символи замінити на обернені (9 - цифра, наприклад, якщо символ '3', то замінити його на 9 - 3 = '6').
//наскільки я зрозумів 2 частину завдання це повинно так виглядати
printf("\n");
for(i=0;i<strlen(str);i++){
    if(str[i]>=97&&str[i]<=122)
    {
        str[i] = str[i] - 32;
    }
    printf("%c", str[i]);
}
printf("\n");
for(i=0;i<strlen(str1);i++){
    if(str1[i]>=48&&str1[i]<=57)
    {
        str1[i] = str1[i] - i;
    }
    printf("%c", str1[i]);
}
//Знайти індекс першого буквенного символа у масиві.
/*for(i=0;i<strlen(str1);i++){
    if(((str1[i]=65&&str1[i]<=90)||(str1[i]>=97&&str1[i]<=122)))
    {
        a = i;
    }
         break;
}
printf("\nindex pershogo bukvenogo sumvoly: %d", a);*/


return 0;
 }
