#pragma once
#include <stdio.h>
#include "main.h"

void infoDraw() {
	system("cls");
	int x = 24;
	int y = 4;
	gotoxy(x, y);
	printf("[���۹�]");
	gotoxy(x, y + 1);
	printf("�̵� : W, A, S, D");
	gotoxy(x, y + 2);
	printf("���� : �����̽���");
	gotoxy(x, y + 10);
	printf("�����̽��� �Է½� ����ȭ������ �̵�");
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}