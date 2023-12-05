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
        gotoxy(x, y + gap);  // 커서 위치 설정
        printf("Gap %d: ", gap);
        print_array(arr, n);
    }
}

int shell() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("쉘 정렬이란?");
    gotoxy(x - 2, y + 2);
    printf("일정한 간격에 있는 요소들을 삽입 정렬로 정렬하고, \n");
    gotoxy(x - 2, y + 3);   
    printf("간격을 점차 줄여가며 정렬하는 알고리즘");
    int arr[5];
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    gotoxy(x - 2, y + 5);
    printf("기존 배열 : ");
    print_array(arr, n);
    gotoxy(x, y + 6);
    shell_sort_with_steps(arr, n, x, y + 6);
    gotoxy(x - 2, y + 5 + n);
    printf("완료된 배열 : ");
    print_array(arr, n);

    gotoxy(x - 2, y + 7 + n);
    printf("쉘 정렬 완료! 아무 키나 누르면 메인화면으로 돌아갑니다.");
    _getch();  // 사용자 키 입력 대기
    return 0;
}