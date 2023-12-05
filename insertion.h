#pragma once
#include <stdio.h>
#include <windows.h>
#include "main.h"
#include <stdlib.h>
#include <time.h>

void insertion_sort_with_steps(int arr[], int n, int x, int y) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        gotoxy(x, y + i - 1);  // Ŀ�� ��ġ ����
        printf("Step %d: ", i);
        print_array(arr, n);
    }
}

int insertion() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("���� �����̶�?");
    gotoxy(x - 2, y + 2);
    printf("�� ���ڸ� ������ ���ڵ� �� ������ ��ġ�� '����'�ϴ� �˰���");
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
    insertion_sort_with_steps(arr, n, x, y + 6);
    gotoxy(x - 2, y + 6 + n);
    printf("�Ϸ�� �迭 : ");
    print_array(arr, n);

    gotoxy(x - 2, y + 8 + n);
    printf("���� ���� �Ϸ�! �ƹ� Ű�� ������ ����ȭ������ ���ư��ϴ�.");
    _getch();  // ����� Ű �Է� ���
    return 0;
}