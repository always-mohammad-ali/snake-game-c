// GAME INITIALIZATION AND MAIN LOOP //

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
 # define WIDTH 30
 # define HEIGHT 20
 # define SPEED 200

int gameover,score;
int x ,y;//snake head position
int fruitx,fruity;//fruit position at x and y axis
int tailx[100],taily[100];
int atail;//tail length
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
enum eDIRECTION dir;

void Setup(){
gameover=0;
dir=STOP;
x=WIDTH/2;
y=LENGTH/2;
fruitx=rand()% WIDTH;
fruity=rand()%HEIGHT;
score=0;
atail=0;}

void RunGame(){
srand(time(0));
Setup();
CONSOLE_CURSOR_INFO
cursorInfo;
GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursorinfo);
 while(!gameOver){
  Draw();
  Input();
  Logic();
  Sleep(SPEED);
  system("cls");
  printf("Game Over!Final Score:%d\n",score);
  printf("Press any key to exit....");
  getch();


}



