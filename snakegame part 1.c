// GAME INITIALIZATION AND MAIN LOOP //

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

 // GAME CONFIGURATION CONSTANTS//
 # define WIDTH 30
 # define HEIGHT 20
 # define SPEED 200

//GLOBAL GAME STATE VARIABLES

int gameover,score;
int x ,y;//snake head position
int fruitX,fruitY;// food position
