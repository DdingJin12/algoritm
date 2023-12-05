#pragma once
#include <stdio.h>
#include <windows.h>
#include "main.h"
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        heapify(arr, n, largest);
    }
}

void heap_sort_with_steps(int arr[], int n, int x, int y) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
        gotoxy(x, y + (n - i));
        printf("Step %d: ", n - i);
        print_array(arr, n);
    }
}

int heap() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("�� �����̶�?");
    gotoxy(x - 2, y + 2);
    printf("���� ���� Ʈ���� ���� �̿��Ͽ� �����ϴ� �˰���");
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
    heap_sort_with_steps(arr, n, x, y + 6);
    gotoxy(x - 2, y + 6 + n);
    printf("�Ϸ�� �迭 : ");
    print_array(arr, n);

    gotoxy(x - 2, y + 8 + n);
    printf("�� ���� �Ϸ�! �ƹ� Ű�� ������ ����ȭ������ ���ư��ϴ�.");
    _getch();  // ����� Ű �Է� ���
    return 0;
}