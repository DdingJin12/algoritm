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
	printf("> BFS(�ʺ� �켱 Ž��)");
	gotoxy(x, y + 2);
	printf("DFS(���� �켱 Ž��)");
	gotoxy(x, y + 4);
	printf("ũ�罺Į �˰���");
	gotoxy(x, y + 6);
	printf("���� �˰���");
	gotoxy(x, y + 8);
	printf("���� ����");
	gotoxy(x, y + 10);
	printf("����\n");
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