#include <iostream>
#include <stdlib.h>
#include<time.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <graphics.h>

#define num_stanze 12
using namespace std;

#define black 0
#define dark_blue 1
#define green 2
#define cyan 3
#define red 4
#define dark_purple 5
#define brown 6
#define gray 7
#define dark_gray 8
#define blue 9
#define neon_green 10
#define light_blue 11
#define light_red 12
#define purple 13
#define yellow 14
#define white 15

void visualizza_stringa (char, char[],int,int,int,int);
void gotoxy(short, short);
void colora(int);

int main()
{
    initwindow(1280,720);
	int stanze [num_stanze][5]={
     {0,999,0,4,0}, // STANZA 1
     {0,0,3,6,0},	// STANZA 2
     {2,0,0,7,2},	// STANZA 3
     {0,1,5,0,0},	// STANZA 4
     {4,0,6,9,0},	// STANZA 5
     {5,2,0,10,1},  // STANZA 6
     {0,3,8,0,0},   // STANZA 7
     {7,0,0,11,0},  // STANZA 8
     {0,5,10,0,1},  // STANZA 9
     {9,6,0,12,0},  // STANZA 10
     {0,8,0,0,0},	// STANZA 11
     {0,10,0,0,2},  // STANZA 12
     };
    char nomi_stanze[num_stanze][100]={
    {"sala del trono"},//1
    {"antro della strega"},//2
    {"covo dell' orco"},//3
    {"giardino oscuro"},//4
    {"antica biblioteca"},//5
    {"sala da ballo"},//6
    {"mansarda"},//7
    {"studio"},//8
    {"taverna"},//9
    {"garage"},//10
    {"bagno"},//11
    {"prigione"}//12
    };
	int stanza,i,direzione=1,minotauro,direzione_minotauro,k;
	bool ripeti,continua=true,fai;
	char vai,input_direzione;
	short int esito;
	srand(time(NULL));
	minotauro=rand()%num_stanze;
	do{
		ripeti=false;
		stanza=rand()%num_stanze; 		//da 0 a num_stanze-1
		for (i=0;i<4;i++)				//se aumentano le colonne della matrice modifica questa istruzione
			if (stanze[stanza][i]==998 || stanze[stanza][i]==999 || stanza==minotauro)
				ripeti=true;
	}while (ripeti);
	//il personaggio si trova in una stanza che non contiene l'ingresso o l'uscita
	do{
        fai=true;
        colora(white);
        settextstyle(9,HORIZ_DIR, 2);
        rectangle(341,193,936,528); 
        line(341,193,0,0);
        line(936,193,1280,0);
        line(341,528,0,720);
        line(936,528,1280,720);
        circle(640,90,75);
        rectangle(620,70,660,110);
        outtextxy(630,7,"N");
        outtextxy(630,155,"S");
        outtextxy(553,83,"W");
        outtextxy(706,83,"E");
		outtextxy(347,200,nomi_stanze[stanza]);
		
		for(i=0;i<4 && fai;i++)
		{
            if(stanze[stanza][i]>0);
                for(k=0;k<4 && fai;k++)
                    if(minotauro==stanze[i][k])
                    {
                        setfillstyle(SOLID_FILL,yellow);
	                    floodfill(640,90,white);
	                    fai=false;
	                    setcolor(black);
                    }
        }
		
        if (stanze[stanza][0]==minotauro || stanze[stanza][1]==minotauro || stanze[stanza][2]==minotauro || stanze[stanza][3]==minotauro)
        	{
	           setfillstyle(SOLID_FILL,RED);
	           floodfill(640,90,white);
	           setcolor(white);
        	}  
                       	   
            switch(direzione)
            {
                case 1:            
                    line(640,90,640,70);break;
            
                case 3:
                    line(640,90,640,110);break;
                case 0:
                    line(620,90,640,90);break;
                case 2:
                    line(660,90,640,90);break;       
            }
            setcolor(white);
            if(stanze[stanza][direzione]>0)
            {
               rectangle(569,310,706,528);
            }
            if(direzione==1)
            {
               if(stanze[stanza][0]>0)
               {
                   line(98,298,222,317);
                   line(222,317,222,595);
                   line(98,298,98,663);
               }
               if(stanze[stanza][2]>0)
               {
                   line(1182,298,1182,663); 
                   line(1058,317,1058,595);
                   line(1058,317,1182,298);
               }
            }
            if(direzione==0)
            {
               if(stanze[stanza][3]>0)
               {
                   line(98,298,222,317);
                   line(222,317,222,595);
                   line(98,298,98,663);
               }
               if(stanze[stanza][1]>0)
               {
                   line(1182,298,1182,663); 
                   line(1058,317,1058,595);
                   line(1058,317,1182,298);
               }
            }
            if(direzione==2)
            {
               if(stanze[stanza][1]>0)
               {
                   line(98,298,222,317);
                   line(222,317,222,595);
                   line(98,298,98,663);
               }
               if(stanze[stanza][3]>0)
               {
                   line(1182,298,1182,663); 
                   line(1058,317,1058,595);
                   line(1058,317,1182,298);
               }
            }
            if(direzione==3)
            {
               if(stanze[stanza][2]>0)
               {
                   line(98,298,222,317);
                   line(222,317,222,595);
                   line(98,298,98,663);
               }
               if(stanze[stanza][0]>0)
               {
                   line(1182,298,1182,663); 
                   line(1058,317,1058,595);
                   line(1058,317,1182,298);
               }
            }
            
        
		//cout<<"\n\npremere wasd per girarsi o la lettera v per entrare: ";
		do{	
		      input_direzione=getch();
              if (input_direzione==224)
                    input_direzione=getch();
		}while(input_direzione!=72 && input_direzione!=75 && input_direzione!=77);
		if (input_direzione==72)
		{
        	do{
	               ripeti=true;
	               direzione_minotauro=rand()%4;
	               if (stanze[minotauro][direzione_minotauro]>0 && stanze[minotauro][direzione_minotauro]!=999 && stanze[minotauro][direzione_minotauro]!=998)
	               {   
	                    //tolgo uno perchè le stanze partono da 0
	                   minotauro=stanze[minotauro][direzione_minotauro]-1;
	                   ripeti=false;
	               }
        	}while (ripeti);
			if(stanze[stanza][direzione]==0)
            {
				//cout<<"\nATTENZIONE non c'e' la porta\n";
				//system("pause");
				outtextxy(500,500,"Non c'è la porta!");
			}
			else
				if (stanze[stanza][direzione]>0)
				{
					switch(stanze[stanza][direzione])
					{	
                        case 998:
                             continua=false;
                             esito=1;break;
                        case 999:
                             continua=false;
                             esito=0;
                             break;
                        default:
                             stanza=stanze[stanza][direzione]-1;
                             direzione=1;
                    }
                }
				else
				{
                  //cout<<"\nquesta porta non si apre da questo lato!\n";
                  //system("pause");
                }
                do{
	               ripeti=true;
	               direzione_minotauro=rand()%4;
	               if (stanze[minotauro][direzione_minotauro]>0 && stanze[minotauro][direzione_minotauro]!=999 && stanze[minotauro][direzione_minotauro]!=998)
	               {   
	                    //tolgo uno perchè le stanze partono da 0
	                   minotauro=stanze[minotauro][direzione_minotauro]-1;
	                   ripeti=false;
	               }
        		}while (ripeti);
		}
		else
		{
			if (input_direzione==75)
			    if(direzione==0)
                    direzione=3;
                else
                    direzione--;
           	if (input_direzione==77)
			    if(direzione==3)
                    direzione=0;
                else
                    direzione++; 
        }
		if (stanza==minotauro)
		{
           	esito=2;
           	continua=false;
        }		
		//system("cls");
		cleardevice();
	}while(continua);

	switch(esito)
    {
	    case 0:
            readimagefile("immagini/hai_vinto.jpg",0,0,1280,720);
			outtextxy(520,600,"hai trovato l'uscita!!!");
            break;	
        case 1:
            readimagefile("immagini/game_over.jpg",0,0,1280,720);
			outtextxy(505,550,"sei caduto nella trappola!");
			break;
        case 2:
            readimagefile("immagini/game_over.jpg",0,0,1280,720);
			outtextxy(505,550,"la bestia ti ha sbranato!");			
			break;
    }
	cout<<"\n\n";
	getch();
	closegraph();
	return 0;	
}








void visualizza_stringa (char riquadro, char stringa[],int x,int y,int colore_stringa, int colore_bordo)
{
	// se riquadro è = il riquadro sarà col doppio bordo
	// se riquadro è _ oppure - il riquadro sarà col bordo singolo
	// se riquadro è un carattere qualsiasi il riquadro sarà costruito con quel carattere
	int i;
	//posizionare il cursore
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	switch (riquadro)
	{
		case '=':
			colora(colore_bordo);
			cout<<(char)201;
			for(i=0;i<=strlen(stringa)-1;i++)
				cout<<(char)205;
			cout<<(char)187;
			y++;
			gotoxy(x,y);
			cout<<(char)186;
			colora(colore_stringa);
			cout<<stringa;
			colora(colore_bordo);
			cout<<(char)186;
			y++;
			gotoxy(x,y);
			cout<<(char)200;
			for(i=0;i<=strlen(stringa)-1;i++)
				cout<<(char)205;
			cout<<(char)188; break;
		case '-':
			colora(colore_bordo);
			cout<<(char)218;
			for(i=0;i<=strlen(stringa)-1;i++)
				cout<<(char)196;
			cout<<(char)191;
			y++;
			gotoxy(x,y);
			cout<<(char)179;
			colora(colore_stringa);
			cout<<stringa;
			colora(colore_bordo);
			cout<<(char)179;
			y++;
			gotoxy(x,y);
			cout<<(char)192;
			for(i=0;i<=strlen(stringa)-1;i++)
				cout<<(char)196;
			cout<<(char)217; break;
		case'_':
			colora(colore_bordo);
			cout<<(char)218;
			for(i=0;i<=strlen(stringa)-1;i++)
				cout<<(char)196;
			cout<<(char)191;
			y++;
			gotoxy(x,y);
			cout<<(char)179;
			colora(colore_stringa);
			cout<<stringa;
			colora(colore_bordo);
			cout<<(char)179;
			y++;
			gotoxy(x,y);
			cout<<(char)192;
			for(i=0;i<=strlen(stringa)-1;i++)
				cout<<(char)196;
			cout<<(char)217; break;
		default:
			colora(colore_bordo);
			for(i=0;i<=strlen(stringa)+1;i++)
				cout<<riquadro;
			y++;
			gotoxy(x,y);
			cout<<riquadro;
			colora(colore_stringa);
			cout<<stringa;
			colora(colore_bordo);
			cout<<riquadro;
			y++;
			gotoxy(x,y);
			for(i=0;i<=strlen(stringa)+1;i++)
				cout<<riquadro;
	}
	colora(white);
}

void gotoxy(short x, short y) 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void colora(int colore) 
{
   HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hCon,colore);
}
