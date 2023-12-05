#pragma once
#include <stdio.h>
#include <windows.h>
#include "main.h"
#include <stdlib.h>
#include <time.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort_with_steps(int arr[], int n, int x, int y) {
    for (int i = 0; i < n - 1; i++) {
        gotoxy(x, y + i);  // 커서 위치 설정
        printf("Step %d: ", i + 1);
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        print_array(arr, n);
    }
}
    
int bubble() {
     system("cls");
     int x = 5;
     int y = 2;
     gotoxy(x - 2, y);
     printf("버블 정렬이란?\n");
     gotoxy(x - 2, y + 2);
     printf("서로 인접한 두 원소를 검사하여 정렬하는 알고리즘\n\n");
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
     bubble_sort_with_steps(arr, n, x, y + 6);
     gotoxy(x - 2, y + 6 + n);
     printf("완료된 배열 : ");
     print_array(arr, n);

     gotoxy(x - 2, y + 8 + n);
     printf("버블 정렬 완료! 아무 키나 누르면 메인화면으로 돌아갑니다.\n");
     _getch();  // 사용자 키 입력 대기
     return 0; 
}