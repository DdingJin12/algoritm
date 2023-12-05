#pragma once
#include <stdio.h>
#include <windows.h>
#include "main.h"
#include <stdlib.h>
#include <time.h>

void merge_sort(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort_with_steps(int arr[], int l, int r, int x, int y) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort_with_steps(arr, l, m, x, y);
        merge_sort_with_steps(arr, m + 1, r, x, y);

        merge_sort(arr, l, m, r);
        gotoxy(x, y + (r - l + 1)); // Ŀ�� ��ġ ����
        printf("Step %d: ", r - l);
        print_array(arr, r + 1);
    }
}

int merge() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("�պ� �����̶�?");
    gotoxy(x - 2, y + 2);
    printf("����Ʈ�� �� ���� �յ��� ũ��� �����ϰ�, ���ҵ� �κ� ����Ʈ�� ������ ��, �� ��");
    gotoxy(x - 2, y + 3);
    printf("�� ���ĵ� �κ� ����Ʈ�� ���Ͽ� ��ü�� ���ĵ� ����Ʈ�� �ǰ� �ϴ� �˰���");
    int arr[5];
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    gotoxy(x - 2, y + 6);
    printf("���� �迭 : ");
    print_array(arr, n);
    gotoxy(x, y + 6);
    merge_sort_with_steps(arr, 0, n - 1, x, y + 6);
    gotoxy(x - 2, y + 6 + n);
    printf("�Ϸ�� �迭 : ");
    print_array(arr, n);

    gotoxy(x - 2, y + 8 + n);
    printf("�պ� ���� �Ϸ�! �ƹ� Ű�� ������ ����ȭ������ ���ư��ϴ�.");
    _getch();  // ����� Ű �Է� ���
    return 0;
}