#pragma once
#include <stdio.h>
#include <windows.h>
#include "main.h"
#include "intro.h"

int stable() {
	system("cls");
	int x = 5;
	int y = 2;
	gotoxy(x - 2, y);
	printf("> ���� ����");
	gotoxy(x, y + 2);
	printf("���� ����");
	gotoxy(x, y + 4);
	printf("���� ����");
	gotoxy(x, y + 6);
	printf("���� ����");
	gotoxy(x, y + 8);
	printf("�� ����");
	gotoxy(x, y + 10);
	printf("�� ����");
	gotoxy(x, y + 12);
	printf("���� ����");
	gotoxy(x, y + 14);
	printf("�� ����");
	gotoxy(x, y + 16);
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
				if (y < 18) {
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