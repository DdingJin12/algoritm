#pragma once
#include <stdio.h>
#include <windows.h>
#include "main.h"

int introDraw() {
	system("cls");
	int x = 5;
	int y = 2;
	gotoxy(x - 2, y);
	printf("> ���� �˰���");
	gotoxy(x, y + 2);
	printf("�׷��� �˰���");
	gotoxy(x, y + 4);
	printf("����ȭ��\n");
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
				if (y < 6) {
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