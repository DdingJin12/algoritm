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

        gotoxy(x, y + i - 1);  // 커서 위치 설정
        printf("Step %d: ", i);
        print_array(arr, n);
    }
}

int insertion() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("삽입 정렬이란?");
    gotoxy(x - 2, y + 2);
    printf("각 숫자를 이전의 숫자들 중 적절한 위치에 '삽입'하는 알고리즘");
    int arr[5];
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    gotoxy(x - 2, y + 4);
    printf("기존 배열 : ");
    print_array(arr, n);
    gotoxy(x, y + 6);
    insertion_sort_with_steps(arr, n, x, y + 6);
    gotoxy(x - 2, y + 6 + n);
    printf("완료된 배열 : ");
    print_array(arr, n);

    gotoxy(x - 2, y + 8 + n);
    printf("삽입 정렬 완료! 아무 키나 누르면 메인화면으로 돌아갑니다.");
    _getch();  // 사용자 키 입력 대기
    return 0;
}