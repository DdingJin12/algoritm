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

        gotoxy(x, y + i);  // 커서 위치 설정
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
    printf("선택 정렬이란?");
    gotoxy(x - 2, y + 2);
    printf("주어진 리스트 중에서 최솟값을 찾아 맨 앞에 위치한 값과 교체하는 알고리즘");
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
    selection_sort_with_steps(arr, n, x, y + 6);
    gotoxy(x - 2, y + 6 + n);
    printf("완료된 배열 : ");
    print_array(arr, n);

    gotoxy(x - 2, y + 8 + n);
    printf("선택 정렬 완료! 아무 키나 누르면 메인화면으로 돌아갑니다.");
    _getch();  // 사용자 키 입력 대기
    return 0;
}