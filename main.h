#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void init() {
	system("mode con cols=81 lines=30 | title 알고리즘");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void titleDraw() {
	printf("\n\n\n\n");
	printf("      ***    *         ****      ****    *****   *  *******  *     *  *     *  \n");
	printf("     *   *   *        *         *    *   *    *  *     *     *     *  **   **  \n");
	printf("    *     *  *       *         *      *  *    *  *     *     *     *  * * * *  \n");
	printf("    *******  *       *    ***  *      *  *****   *     *     *******  *  *  *  \n");
	printf("    *     *  *       *      *  *      *  *    *  *     *     *     *  *     *  \n");
	printf("    *     *  *        *    *    *    *   *    *  *     *     *     *  *     *  \n");
	printf("    *     *  *******   ****      ****    *    *  *     *     *     *  *     *  \n");
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int keyControl() {
	char temp = _getch();
	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') {
		return SUBMIT;
	}
}

int menuDraw() {
	int x = 34;
	int y = 14;
	gotoxy(x - 2, y);
	printf("> 알고리즘 소개");
	gotoxy(x, y + 1);
	printf("프로그램 정보");
	gotoxy(x, y + 2);
	printf("    종료\n");
	printf("\n\n\n");
	while (1) {
		int n = keyControl();
		switch (n) {
			case UP: {
				if (y > 14) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, --y);
					printf(">");
				}
				break;
			}
			case DOWN: {
				if (y < 16) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				return y - 14;
			}
		}
	}
}