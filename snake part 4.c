#include <stdio.h>

int main(){
void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Draw() {
    gotoxy(0, 0); // Reset cursor position

    // Draw top border
    printf(" ");
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    return 0;
}
