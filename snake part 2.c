
//INPUT HANDLING

void Input() {
    if (_kbhit()) {  // Non-blocking input check
        switch (_getch()) {
            case 'a': if (dir != RIGHT) dir = LEFT; break;
            case 'd': if (dir != LEFT) dir = RIGHT; break;
            case 'w': if (dir != DOWN) dir = UP; break;
            case 's': if (dir != UP) dir = DOWN; break;
            case 'x': gameOver = 1; break;
        }
    }
}
