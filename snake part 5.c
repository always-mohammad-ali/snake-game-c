#include <stdio.h>
#include <windows.h>

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


