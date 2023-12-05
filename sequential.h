#pragma once
#include <stdio.h>
#include <windows.h>
#include "main.h"
#include <stdlib.h>
#include <time.h>

void sequential_sort_with_steps(int arr[], int n, int x, int y) {
    for (int i = 0; i < n; i++) {
        gotoxy(x, y + i);  // 커서 위치 설정
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
    printf("순차 정렬이란?");
    gotoxy(x - 2, y + 2);
    printf("맨 앞에서부터 제일 작은 원소를 배치하게 만들어 나가는 알고리즘");
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
    sequential_sort_with_steps(arr, n, x, y + 6);
    gotoxy(x - 2, y + 7 + n);
    printf("완료된 배열 : ");
    print_array(arr, n);

    gotoxy(x - 2, y + 9 + n);
    printf("순차 정렬 완료! 아무 키나 누르면 메인화면으로 돌아갑니다.");
    _getch();  // 사용자 키 입력 대기
    return 0;
}