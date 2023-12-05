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
        gotoxy(x, y + (r - l + 1)); // 커서 위치 설정
        printf("Step %d: ", r - l);
        print_array(arr, r + 1);
    }
}

int merge() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("합병 정렬이란?");
    gotoxy(x - 2, y + 2);
    printf("리스트를 두 개의 균등한 크기로 분할하고, 분할된 부분 리스트를 정렬한 후, 두 개");
    gotoxy(x - 2, y + 3);
    printf("의 정렬된 부분 리스트를 합하여 전체가 정렬된 리스트가 되게 하는 알고리즘");
    int arr[5];
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    gotoxy(x - 2, y + 6);
    printf("기존 배열 : ");
    print_array(arr, n);
    gotoxy(x, y + 6);
    merge_sort_with_steps(arr, 0, n - 1, x, y + 6);
    gotoxy(x - 2, y + 6 + n);
    printf("완료된 배열 : ");
    print_array(arr, n);

    gotoxy(x - 2, y + 8 + n);
    printf("합병 정렬 완료! 아무 키나 누르면 메인화면으로 돌아갑니다.");
    _getch();  // 사용자 키 입력 대기
    return 0;
}