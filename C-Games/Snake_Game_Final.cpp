// Snake Game in C++ (Console Version)
// Works best in Windows with a compiler that supports windows.h and conio.h

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

using namespace std;

int length;
int bend_no;
int len;
char key;
int life;
int foodX, foodY, flag;
bool gameOver = false;

struct coordinate {
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;

coordinate head, bend[500], body[30];

void delay_snake(float secs) {
    int ms = (int)(secs * 1000);
    Sleep(ms); // works only on Windows
}

void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void food() {
    if (flag == 0) {
        foodX = rand() % 48 + 1;
        foodY = rand() % 23 + 1;
        flag = 1;
    }
    gotoxy(foodX, foodY);
    cout << "@";
}

void boarder() {
    for (int i = 0; i <= 50; i++) {
        gotoxy(i, 0); cout << "#";
        gotoxy(i, 25); cout << "#";
    }
    for (int i = 0; i <= 25; i++) {
        gotoxy(0, i); cout << "#";
        gotoxy(50, i); cout << "#";
    }
}

void Print() {
    gotoxy(52, 5); cout << "Score: " << length - 5;
    gotoxy(52, 6); cout << "Life: " << life;
}

void bend_snake() {
    bend_no++;
    bend[bend_no] = head;
}

bool check_self_collision() {
    for (int i = 0; i < length; i++) {
        if (head.x == body[i].x && head.y == body[i].y) {
            return true;
        }
    }
    return false;
}

void move_snake() {
    coordinate prev = head, temp;

    switch (head.direction) {
        case UP: head.y--; break;
        case DOWN: head.y++; break;
        case LEFT: head.x--; break;
        case RIGHT: head.x++; break;
    }

    // Teleport horizontally (wrap around)
    if (head.x <= 0) head.x = 49;
    else if (head.x >= 50) head.x = 1;

    // Collision with top and bottom walls
    if (head.y <= 0 || head.y >= 25) {
        gameOver = true;
        return;
    }

    // Check self collision
    if (check_self_collision()) {
        gameOver = true;
        return;
    }

    for (int i = 0; i < length; i++) {
        temp = body[i];
        body[i] = prev;
        prev = temp;
    }

    gotoxy(head.x, head.y); cout << "O";
    for (int i = 0; i < length; i++) {
        gotoxy(body[i].x, body[i].y); cout << "o";
    }

    gotoxy(0, 26);
    delay_snake(0.1);
    system("cls");
    boarder();
    Print();
}

void move() {
    while (!gameOver) {
        food();
        if (_kbhit()) {
            key = _getch();
            if ((key == 'a' || key == 'A') && head.direction != RIGHT)
                head.direction = LEFT;
            else if ((key == 'd' || key == 'D') && head.direction != LEFT)
                head.direction = RIGHT;
            else if ((key == 'w' || key == 'W') && head.direction != DOWN)
                head.direction = UP;
            else if ((key == 's' || key == 'S') && head.direction != UP)
                head.direction = DOWN;
            else if (key == 27) exit(0);
        }

        // Check if snake eats food
        if (head.x == foodX && head.y == foodY) {
            length++;
            flag = 0; // Trigger new food spawn
        }

        bend_snake();
        move_snake();
    }

    gotoxy(20, 12);
    cout << "Game Over!";
    gotoxy(20, 13);
    cout << "Final Score: " << length - 5;
    getch();
}

void load() {
    system("cls");
    gotoxy(20, 10);
    cout << "Loading...";
    for (int r = 0; r <= 20; r++) {
        for (int q = 0; q <= 10000000; q++);
        cout << (char)177;
    }
    getch();
}

int main() {
    srand(time(0)); // Seed the random generator once
    system("cls");
    load();
    length = 5;
    head.x = 25;
    head.y = 20;
    head.direction = RIGHT;
    bend[0] = head;
    boarder();
    food();
    life = 3;
    bend_no = 0;
    len = 0;
    move();
    return 0;
}
