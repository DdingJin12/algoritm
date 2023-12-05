#pragma once
#pragma once
#include <stdio.h>
#include <windows.h>
#include "main.h"
#include "intro.h"

int graph() {
	system("cls");
	int x = 5;
	int y = 2;
	gotoxy(x - 2, y);
	printf("> BFS(너비 우선 탐색)");
	gotoxy(x, y + 2);
	printf("DFS(깊이 우선 탐색)");
	gotoxy(x, y + 4);
	printf("크루스칼 알고리즘");
	gotoxy(x, y + 6);
	printf("프림 알고리즘");
	gotoxy(x, y + 8);
	printf("위상 정렬");
	gotoxy(x, y + 10);
	printf("종료\n");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 2) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, y -= 2);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 12) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, y += 2);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 2;
		}
		}
	}
}