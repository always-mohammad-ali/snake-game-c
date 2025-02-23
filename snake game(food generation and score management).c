#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#define WIDTH 30
#define HEIGHT 20
#define SPEED 200

int x,y;
int fruitX, fruitY;
int score;

int main()
{
    
    //food generation :

    void GenerateFood(){
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    }
    
    //score management :

    void UpdateScore(int points){
        score += points;
    }

}