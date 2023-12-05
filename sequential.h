#pragma once
#include <stdio.h>
#include <windows.h>
#include "main.h"
#include <stdlib.h>
#include <time.h>

void sequential_sort_with_steps(int arr[], int n, int x, int y) {
    for (int i = 0; i < n; i++) {
        gotoxy(x, y + i);  // Ŀ�� ��ġ ����
        printf("Step %d: ", i + 1);
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        print_array(arr, n);
    }
}

int sequential() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("���� �����̶�?");
    gotoxy(x - 2, y + 2);
    printf("�� �տ������� ���� ���� ���Ҹ� ��ġ�ϰ� ����� ������ �˰���");
    int arr[5];
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    gotoxy(x - 2, y + 4);
    printf("���� �迭 : ");
    print_array(arr, n);
    gotoxy(x, y + 6);
    sequential_sort_with_steps(arr, n, x, y + 6);
    gotoxy(x - 2, y + 7 + n);
    printf("�Ϸ�� �迭 : ");
    print_array(arr, n);

    gotoxy(x - 2, y + 9 + n);
    printf("���� ���� �Ϸ�! �ƹ� Ű�� ������ ����ȭ������ ���ư��ϴ�.");
    _getch();  // ����� Ű �Է� ���
    return 0;
}