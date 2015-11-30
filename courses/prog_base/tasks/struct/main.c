
//1.Плейліст музики. Кількість плейлістів у яких менше 5 композицій. Перейменувати плейліст.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct PlayList{
char name [20];
int  a;//chuslo kompozuzii
float time;
};
int count(int size, struct PlayList arr[size]);
void change(struct PlayList * pVar, const char * newValue);
void print(struct PlayList * pVar);
int main(){
struct PlayList b[20];
int i;
for(i=0;i<4;i++){
fflush(stdin);
printf("enter name\n");
gets(b[i].name);
printf("enter number\n");
scanf("%i", &b[i].a);
printf("Vedit chas aydiozapusy: ");
scanf("%lf", &b[i].time);
}
fflush(stdin);
int val;
char newName[20];
printf("Vedit nomer playlisty: ");
scanf("%i", &val);
fflush(stdin);
gets(newName);
change(&(b[val]), newName);
printf("Vasha Kilkist playlistiv: %i\n", count(4, b));
print(&b[val]);
return 0;
}



int count(int size, struct PlayList arr[size])
{
int i;
int p=0;
for(i=0;i<size;i++)
{
    if(arr[i].a >= 5)
    p++;
}
return p;
}
void change(struct PlayList * pVar, const char * newValue)

{
    strcpy(pVar->name, newValue);

}
void print(struct PlayList * pVar)

{

    puts(pVar->name);
    printf("Kilkist pisen: %i", pVar->a);
}

