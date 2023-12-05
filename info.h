#pragma once
#include <stdio.h>
#include "main.h"

void infoDraw() {
	system("cls");
	int x = 24;
	int y = 4;
	gotoxy(x, y);
	printf("[조작법]");
	gotoxy(x, y + 1);
	printf("이동 : W, A, S, D");
	gotoxy(x, y + 2);
	printf("선택 : 스페이스바");
	gotoxy(x, y + 10);
	printf("스페이스바 입력시 메인화면으로 이동");
	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}