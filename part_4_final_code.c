
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
