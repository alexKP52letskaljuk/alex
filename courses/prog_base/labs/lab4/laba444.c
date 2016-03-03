#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

const int zemlyanudamage = 5;
const int marsianudamage  = 10;
const int zemlyanuspeed = 9;
const int marsianuspeed = 6;
const int zemlyanuarmor = 10;
const int marsianuarmor = 20;
const int zemlyanuhealth  = 100;
const int marsianuhealth = 120;
const int klaszemlyanu = 0;
const int klasmarsianu = 1;


struct Rasa
{
	char name[20];
	int damage;
	int weapon;
	int health;
	int speed;
	int armor;
	int klas;
};

void Pos(int X,int Y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=X;
    pos.Y=Y;
    SetConsoleCursorPosition(hConsole, pos);
}

void printborder(void){
	int i , j;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;

for(i=0; i<150; i++){
		pos.X=i;
        pos.Y=0;
        printf("*");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_RED);
        SetConsoleCursorPosition(hConsole, pos);
		}
for(i=0; i<150; i++)
{
    pos.X=i;
        pos.Y=90;
        printf("*");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_RED);
        SetConsoleCursorPosition(hConsole, pos);
}
for(i = 0 ; i <=90 ; i++){
	pos.X =90;
	pos.Y=i;
        printf("*");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_RED);
        SetConsoleCursorPosition(hConsole, pos);
		}


for (j=0;j<=90;j++){

      {pos.X=149;
        pos.Y=j;
        printf("*");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_RED);
        SetConsoleCursorPosition(hConsole, pos);
		}
}

	Pos(1,41);

}

void addMarsianin(struct Rasa *pbot ){
	char text[20];
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
		Pos (2,3);
		SetConsoleTextAttribute(hConsole,7);
     printf("vvedite imya personaga:\n");
Pos(2  , 4);
	Pos( 2 , 4);
	 fflush(stdin);
        gets(pbot->name);
        Pos(2 , 3);
puts("                                                      ");
        fflush(stdin);
		SetConsoleTextAttribute(hConsole,7);
}

void stata(struct Rasa *p){
	char klas[150];
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
		Pos (2,3);
		SetConsoleTextAttribute(hConsole,7);
		puts("viberete rasy(zemlanu / marsianu)");
		Pos (2,6);
		gets(klas);
		Pos(2 , 3);
		puts ("                                                           ");
		fflush(stdin);

	if(strcmp(klas , "t") ==0)
	{

		p -> damage = zemlyanudamage;
			p -> speed = zemlyanuspeed;
				p -> armor = zemlyanuarmor;
				p -> health = zemlyanuhealth;
				p -> klas = klaszemlyanu;

	}
	else if ( strcmp(klas , "ct") == 0){

			p -> damage = marsianudamage;
				p -> speed = marsianuspeed;
					p -> armor = marsianuarmor;
					p -> health = marsianuhealth;
					p -> klas = klasmarsianu;
	}


}

void naboru( struct Rasa *pvar){
	char armor[50];
	char weapon[50];
	char str[50];
	char b[50];
	char c[50];
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    Pos(2 , 8);
  //  system("cls");
	if (pvar-> klas == 0){
		puts("viberete armor i weapon\n");
		Pos(2 , 9);
		gets(str);
		fflush(stdin);
		if( strcmp(str , "armor") == 0){
			Pos( 2, 10);
			puts("spisok armora:\n");

					puts ("Magic Armor:\nhealth +20\nspeed - 10\narmor + 30\ndamage +5\n");

						puts ("Black iron Armor:\nhealth +22\nspeed - 13\narmor +34\ndamage +7\n");

							puts ("Gold Armor:\nhealth +25\nspeed - 16\narmor +37\ndamage +10\n");
			gets(armor);
			if(strcmp(armor , "Magic Armor") == 0){
				pvar -> health += 20;
				pvar -> speed  -= 10;
				pvar -> armor  += 30;
				pvar -> damage += 5;
			}
			else if(strcmp(armor , "Black iron Armor") == 0){
				pvar -> health += 22;
				pvar -> speed  -= 13;
				pvar -> armor  += 34;
				pvar -> damage +=  7;

			}

			else if(strcmp(armor , "Gold Armor") == 0){

				pvar -> health += 25;
				pvar -> speed  -= 16;
				pvar -> armor  += 37;
				pvar -> damage += 10;
			}
	}


	else if(strcmp(str,"weapon") == 0){

			Pos(2,11);
			puts("List of weapon:\n");
			puts("guns\tautomat\t");


		gets(b);
		if(strcmp(b , "automat") == 0){
			puts("blaster:\nhealth +4\nspeed - 1\narmor + 2\ndamage +9\n");
			puts("lightsaber:\nhealth +4\nspeed - 2\narmor + 3\ndamage +10\n");
		}
			gets(c);
			if(strcmp( c , "blaster") == 0){

				pvar -> health += 4;
				pvar -> speed  -= 1;
				pvar -> armor  += 2;
				pvar -> damage += 9;
			}
			if(strcmp(c  ,"lightsaber") == 0){

				pvar -> health += 4;
				pvar -> speed  -= 2;
				pvar -> armor  += 3;
				pvar -> damage += 10;
			}
			if(strcmp(b , "guns") == 0){
				puts("Glock:\n health +1\nspeed -1\narmor +1\ndamage +4\n");
				puts("Revolver:\n health +4\nspeed -3\narmor + 2\ndamage +6\n");
				puts("Dual pistols:\n health + 1\nspeed - 2\narmor + 1\ndamage +4\n");
			}
			gets(c);
			if(strcmp(c , "Glock") == 0){
				pvar -> health += 1;
				pvar -> speed  -= 1;
				pvar -> armor  += 1;
				pvar -> damage += 4;
			}
			if(strcmp( c , "Revolver") == 0){
				pvar -> health += 4;
				pvar -> speed  -= 3;
				pvar -> armor  +=2;
				pvar -> damage += 6;

			}
			if(strcmp(c , "Dual pistols") == 0){

				pvar -> health += 1;
				pvar -> speed  -= 2;
				pvar -> armor  +=1;
				pvar -> damage += 4;
			}

	}
}
 	else if(pvar-> klas == 1){


	puts("viberete armor i weapon\n");
		Pos(2 , 9);
		gets(str);
		fflush(stdin);

		if(strcmp(str , "armor") == 0){

			puts("List of armor:\n");

		puts("Silicon:health +11\nspeed -15\narmor + 16\n");
		puts ("Iron:health +9\nspeed - 12\narmor + 12\n ");
		puts ("Utumateria :health + 4\nspeed -8\narmor +7");
			gets(armor);
			if(strcmp(armor , "Silicon") == 0){
				pvar -> health += 11;
				pvar -> speed  -= 15;
				pvar -> armor  += 16;

			}
			if(strcmp(armor , "Iron") == 0){
				pvar -> health += 9;
				pvar -> speed  -= 8;
				pvar -> armor  += 7;


			}
			if(strcmp(armor , "Utumateria") == 0){

				pvar -> health += 4;
				pvar -> speed  -= 8;
				pvar -> armor  += 7;

			}

}
else if(strcmp(str,"weapon") == 0){

			Pos(2,11);
			puts("List of weapon:\n");
			puts("flaces\tpistols\t");

		gets(b);
		if(strcmp(b , "flaces") == 0){

			puts("bjb-10:\nspeed -4\narmor +2\ndamage +9\n");
			puts("cosmos blaster:\nspeed -5;\narmor + 3\ndamage +10 ");
		}
		fflush(stdin);
		gets(c);
		if(strcmp(c , "bjb-10") == 0){

				pvar -> speed  -= 4;
				pvar -> armor  += 2;
				pvar -> damage +=9;
		}
		if(strcmp(c , "cosmos blaster") == 0){
				pvar -> speed  -= 5;
				pvar -> armor  += 3;
				pvar -> damage += 10;
		}
			if(strcmp(b , "pistols") == 0){
				puts ("p2000 : speed - 6\narmor +3\ndamage + 12\n");
				puts ("baret M9: speed - 10\narmor +5\ndamage +15\n");
				puts ("UMP: speed - 7\narmor + 1\ndamage + 8\n");
			}
				fflush(stdin);
					gets(c);
						if(strcmp(c , "P2000") == 0){

				pvar -> speed  -= 6;
				pvar -> armor  += 3;
				pvar -> damage +=12;
		}
			if(strcmp(c , "baret M9") == 0){

				pvar -> speed  -= 10;
				pvar -> armor  += 5;
				pvar -> damage +=15;
		}

			if(strcmp(c , "UMP") == 0){

				pvar -> speed  -= 7;
				pvar -> armor  += 1;
				pvar -> damage += 8;
		}
			fflush(stdin);

}
}
}

int batle(struct Rasa *pvar , struct Rasa *pbot){

	double powervar;
	double powerbot;

	powervar = pvar->health	/(pbot->speed * pbot ->damage - pvar->armor);
	powerbot =  pbot->health	/(pvar->speed * pvar ->damage - pbot->armor);
	Pos (91,15);

	if(powervar > powerbot)

	printf(" Win -----> %s" , pvar->name);

	else

	printf(" Win -----> %s" , pbot->name);

}

void save (struct Rasa *pbot , struct Rasa *pvar){

	FILE * fp;
	fp = fopen ("res.txt" , "w");
	fprintf(fp , "%i %i %i %i %s\n" , pvar -> damage ,pvar -> speed , pvar ->armor , pvar->health, pvar->name );
	fprintf(fp , "%i %i %i %i %s" , pbot -> damage ,pbot -> speed , pbot ->armor , pbot->health, pbot->name );
	fclose(fp);


}
void load(struct Rasa * pbot, struct Rasa * pvar){

	FILE * fp;

	fp = fopen("res.txt" , "r");

	fscanf(fp , "%i %i %i %i %s\n" , &(pvar -> damage ),&(pvar -> speed ), &(pvar ->armor ), &(pvar->health), &(pvar->name) );
	fscanf(fp , "%i %i %i %i %s" , &(pbot -> damage ),&(pbot -> speed ), &(pbot ->armor ), &(pbot->health ), &(pbot->name ));
	fclose(fp);

}


int main(void) {
	char n[520];
puts("Hochete prodovgutu poperedny gry(yes / no)\n");
gets(n);
	struct Rasa *pbot;
	struct Rasa *pvar;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
	printborder();
	pvar = malloc(sizeof(struct Rasa));
	pbot = malloc(sizeof(struct Rasa));
	 addMarsianin(pvar);




if (strcmp( n ,"yes") == 0){
	 load(pbot, pvar);

	batle(pvar ,pbot);
	return 0;
}
	 stata(pvar);
	 Pos(2,7);
	 printf("damage: %i speed: %i armor: %i health:%i" , pvar -> damage ,pvar -> speed , pvar ->armor , pvar->health);
	 Pos (2, 8);
	 naboru(pvar);
	 system("cls");
	 printborder();
	 Pos(2,3);
	 	SetConsoleTextAttribute(hConsole,7);
	  printf("damage: %i speed: %i armor: %i health:%i " , pvar -> damage ,pvar -> speed , pvar ->armor , pvar->health);
	  naboru(pvar);
	  system("cls");
	  printborder();
	  Pos(91 , 5);
	  	SetConsoleTextAttribute(hConsole,7);
	  printf("Zemlyanun %s " ,pvar->name);
	 // puts(pvar->name);
	  Pos(91,6);
	  	SetConsoleTextAttribute(hConsole,7);
	  printf("damage: %i speed: %i armor: %i health:%i " , pvar -> damage ,pvar -> speed , pvar ->armor , pvar->health);
	  addMarsianin(pbot);
	 //  Pos(91,6);
	  	SetConsoleTextAttribute(hConsole,7);

		stata(pbot);
			 Pos(2,7);
	 printf("damage: %i speed: %i armor: %i health:%i" , pbot -> damage ,pbot -> speed , pbot ->armor , pbot->health);
	 naboru(pbot);
	  system("cls");
	   Pos(91 , 1);
	  	SetConsoleTextAttribute(hConsole,7);
	  	printf("Zemlyanun ");
	  	puts(pvar->name);
        printborder();
	   Pos(91,2);
	  	SetConsoleTextAttribute(hConsole,7);
	 printf("damage: %i speed: %i armor: %i health:%i " , pvar -> damage ,pvar -> speed , pvar ->armor , pvar->health);
	   // Pos(91 , 14);
	  	SetConsoleTextAttribute(hConsole,7);

	  Pos(91 , 4);
	  SetConsoleTextAttribute(hConsole,7);
		 naboru(pbot);
		 	  Pos(91 , 5);
		 printf("Zemlyanun ");

		 puts (pbot->name);
		 Pos(91,6);
		 	 printf("damage: %i speed: %i armor: %i health:%i" , pbot -> damage ,pbot -> speed , pbot ->armor , pbot->health);
		 	 save (pbot ,pvar);
			  batle(pvar ,pbot);

		return 0;
}
