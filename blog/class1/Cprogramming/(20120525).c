#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define ESC	27
#define DIRECTION_KEYBOARD	224
#define UP     72
#define DOWN   80
#define LEFT   75
#define RIGHT  77

int R_X=0,R_Y=0,X=10,Y=2,Round=1,Eat=0,DELAY=200;
char String[8][8] = {{"※ ※"},{"離 每"},{"開 吃"},{"請 五"},{"按 個"},{"Ｅ 加"},{"Ｓ 一"},{"Ｃ 關"}};

void gotoxy(int x, int y){
 	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
}

void SetCursorVisible(BOOL _bVisible,DWORD _dwSize){
	CONSOLE_CURSOR_INFO CCI;
	CCI.bVisible = _bVisible;
	CCI.dwSize = _dwSize;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CCI);
}

void RandXY(void){
    srand(time(NULL));
    R_X = rand() % 49;if(R_X<10) R_X += 10;
    R_Y = rand() % 22;if(R_Y<2) R_Y += 2;
}

void PrintRXY(void){
     gotoxy(R_X,R_Y);
     printf("◎");
}

void PrintInfo(void){
     gotoxy(0,0);
     printf("  Round：%d  Eat：%d  Head：%d,%d  Cookie：%d,%d",Round,Eat,X,Y,R_X,R_Y);
     gotoxy(X,Y);
}

void PrintTable(int G_start){
     int i=0,j=0;
     PrintInfo();
     gotoxy(0,1);
     printf("\t┌========================================┐\n");
     for(i=0;i<20;i++){
       if(i<8) printf("%s",String[i]);
       if(i==9 && G_start== 0){
         printf("\t│          !!!!GAME START!!!!            │\n");
       }else if(i==9 && G_start!= 0){
         printf("\t│                                        │\n");
       }
       printf("\t│                                        │\n");
     }
     printf("\t└========================================┘\n");
     PrintRXY();
}

int main(){
	unsigned short int ch1,ch2,C_esc=0,C_W=0;
	int i=0,j=0;
	int G_start=0;
	
    RandXY();
    PrintTable(G_start);gotoxy(X,Y);
    SetCursorVisible(TRUE,100);
	    
    while(1){
	    ch1 = getch();
	    G_start = 1;PrintTable(G_start);gotoxy(X,Y);
	    if(ch1 == ESC){
           C_esc = 1;
	       break;
        }
        else if(ch1 == DIRECTION_KEYBOARD){
           ch2 = getch();
           switch(ch2){
              case UP:
			     do{
		           gotoxy(X,--Y);
		           PrintInfo();
		           if((X==R_X && Y==R_Y) || (X==R_X+1 && Y==R_Y)){
                     system("CLS");
                     if(Eat!=0 && (Eat%4)==0){Round++;DELAY-=20;};Eat++;R_X=0;R_Y=0;
                     RandXY();PrintRXY();PrintTable(G_start);
                   }
                   if( Y==1){
                     gotoxy(15,10);
                     printf("##GAME OVER##");
                     goto END;
                   }
		           Sleep(DELAY);
		           if(kbhit()) break;
                 }while(Y>0);
			     break;
              case DOWN:
			     do{
                   if( Y==22 ){
			         gotoxy(15,10);
                     printf("##GAME OVER##");
                     goto END;
                   }
		           gotoxy(X,++Y);
		           PrintInfo();
		           if((X==R_X && Y==R_Y) || (X==R_X+1 && Y==R_Y)){
                     system("CLS");
                     if(Eat!=0 && (Eat%4)==0){Round++;DELAY-=20;};Eat++;R_X=0;R_Y=0;
                     RandXY();PrintRXY();PrintTable(G_start);
                   }
                   Sleep(DELAY);
		           if(kbhit()) break;
                 }while(Y<23);
			     break;
              case LEFT:
			     do{
		           gotoxy(--X,Y);
		           PrintInfo();
		           if((X==R_X && Y==R_Y) || (X==R_X+1 && Y==R_Y)){
                     system("CLS");
                     if(Eat!=0 && (Eat%4)==0){Round++;DELAY-=20;};Eat++;R_X=0;R_Y=0;
                     RandXY();PrintRXY();PrintTable(G_start);
                   }
                   if( X==9 ){
				     gotoxy(15,10);
                     printf("##GAME OVER##");
                     goto END;
                   }
		           Sleep(DELAY-50);
		           if(kbhit()) break;
                 }while(X>8);
			     break;
               case RIGHT:
			     do{
                   if( X==49){
				     gotoxy(15,10);
                     printf("##GAME OVER##");
                     goto END;
                   }
		           gotoxy(++X,Y);
		           PrintInfo();
		           if((X==R_X && Y==R_Y) || (X==R_X+1 && Y==R_Y)){
                     system("CLS");
                     if(Eat!=0 && (Eat%4)==0){Round++;DELAY-=20;};Eat++;R_X=0;R_Y=0;
                     RandXY();PrintRXY();PrintTable(G_start);
                   }
		           Sleep(DELAY-50);
		           if(kbhit()) break;
                 }while(X<50);
			     break;
	       }
        }
    }
END:
    gotoxy(15,11);
    printf("總共玩了 %d 回合,吃了 %d 個",Round,Eat);
    gotoxy(15,12);
    system("PAUSE");
}
