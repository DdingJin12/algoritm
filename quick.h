#pragma once
#include <stdio.h>
#include <windows.h>
#include "main.h"
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quick_sort_with_steps(int arr[], int low, int high, int x, int y, int* step) {
    if (low < high) {
        int pi = partition(arr, low, high);
        gotoxy(x, y + (*step));
        printf("Step %d: ", *step);
        print_array(arr, high + 1);
        (*step)++;

        quick_sort_with_steps(arr, low, pi - 1, x, y, step);
        quick_sort_with_steps(arr, pi + 1, high, x, y, step);
    }
}

int quick() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("퀵 정렬이란?");
    gotoxy(x - 2, y + 2);
    printf("피벗 값을 기준으로 리스트를 두 개로 나누며 정렬하는 알고리즘");
    int arr[5];
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    gotoxy(x - 2, y + 4);
    printf("기존 배열 : ");
    print_array(arr, n);
    int step = 1;
    quick_sort_with_steps(arr, 0, n - 1, x, y + 5, &step);
    gotoxy(x - 2, y + 6 + step);
    printf("완료된 배열 : ");
    print_array(arr, n);

    gotoxy(x - 2, y + 8 + step);
    printf("퀵 정렬 완료! 아무 키나 누르면 메인화면으로 돌아갑니다.");
    _getch();  // 사용자 키 입력 대기
    return 0;
}