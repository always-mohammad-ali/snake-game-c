
//1. GAME INITIALIZATION & MAIN LOOP (Farden Hossain)

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


#define WIDTH 30
#define HEIGHT 20
#define SPEED 200


int gameOver, score;
int x, y;           
int fruitX, fruitY; 
int tailX[100], tailY[100]; 
int nTail;          
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;


void Setup()
{
    gameOver = 0;
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    nTail = 0;
}


void RunGame()
{
    srand(time(0));
    Setup();

    
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    while (!gameOver)
    {
        
        Draw();
        Input();
        Logic();
        Sleep(SPEED);
    }

    
    system("cls");
    printf("Game Over! Final Score: %d\n", score);
    printf("Press any key to exit...");
    _getch();
}


//2. INPUT HANDLING (Jayonti Sarkar)

void Input()
{
    if (_kbhit())    
    {
        switch (_getch())
        {
        case 'a':
            if (dir != RIGHT) dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT) dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN) dir = UP;
            break;
        case 's':
            if (dir != UP) dir = DOWN;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}


//3. SNAKE MECHANICS (Afif Chowdhury)

void Logic()
{
    
    int prevX = tailX[0];
    int prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        int tempX = tailX[i];
        int tempY = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = tempX;
        prevY = tempY;
    }

   
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        gameOver = 1;

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    }

    
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }
}


//4. RENDERING SYSTEM (Mohammad Ali)

void gotoxy(int x, int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Draw()
{
    gotoxy(0, 0); 

    
    printf(" ");
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

   
    for (int i = 0; i < HEIGHT; i++)
    {
        printf(" #");
        for (int j = 0; j < WIDTH; j++)
        {
           
            if (i == y && j == x) printf("O");
           
            else if (i == fruitY && j == fruitX) printf("F");
           
            else
            {
                int isTail = 0;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        printf("o");
                        isTail = 1;
                        break;
                    }
                }
                if (!isTail) printf(" ");
            }
        }
        printf("# \n");
    }

   
    printf(" ");
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\nScore: %d", score);
}


//5. FOOD & SCORE SYSTEM (MD. Nahim)

void GenerateFood()
{
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
}

void UpdateScore(int points)
{
    score += points;
}

int main()
{
    RunGame();
    return 0;
}
