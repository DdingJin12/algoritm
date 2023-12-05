#pragma once
#include <stdio.h>
#include <windows.h>
#include "main.h"
#include <stdlib.h>
#include <time.h>
#include "bubble.h"

void shell_sort_with_steps(int arr[], int n, int x, int y) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
        gotoxy(x, y + gap);  // Ŀ�� ��ġ ����
        printf("Gap %d: ", gap);
        print_array(arr, n);
    }
}

int shell() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("�� �����̶�?");
    gotoxy(x - 2, y + 2);
    printf("������ ���ݿ� �ִ� ��ҵ��� ���� ���ķ� �����ϰ�, \n");
    gotoxy(x - 2, y + 3);   
    printf("������ ���� �ٿ����� �����ϴ� �˰���");
    int arr[5];
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    gotoxy(x - 2, y + 5);
    printf("���� �迭 : ");
    print_array(arr, n);
    gotoxy(x, y + 6);
    shell_sort_with_steps(arr, n, x, y + 6);
    gotoxy(x - 2, y + 5 + n);
    printf("�Ϸ�� �迭 : ");
    print_array(arr, n);

    gotoxy(x - 2, y + 7 + n);
    printf("�� ���� �Ϸ�! �ƹ� Ű�� ������ ����ȭ������ ���ư��ϴ�.");
    _getch();  // ����� Ű �Է� ���
    return 0;
}