#pragma once
#include <stdio.h>
#include <windows.h>
#include "main.h"
#include <stdlib.h>
#include <time.h>

void selection_sort_with_steps(int arr[], int n, int x, int y) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        gotoxy(x, y + i);  // Ŀ�� ��ġ ����
        printf("Step %d: ", i + 1);
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        print_array(arr, n);
    }
}

int selection() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("���� �����̶�?");
    gotoxy(x - 2, y + 2);
    printf("�־��� ����Ʈ �߿��� �ּڰ��� ã�� �� �տ� ��ġ�� ���� ��ü�ϴ� �˰���");
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
    selection_sort_with_steps(arr, n, x, y + 6);
    gotoxy(x - 2, y + 6 + n);
    printf("�Ϸ�� �迭 : ");
    print_array(arr, n);

    gotoxy(x - 2, y + 8 + n);
    printf("���� ���� �Ϸ�! �ƹ� Ű�� ������ ����ȭ������ ���ư��ϴ�.");
    _getch();  // ����� Ű �Է� ���
    return 0;
}