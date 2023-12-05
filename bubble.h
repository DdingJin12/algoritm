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
        gotoxy(x, y + i);  // Ŀ�� ��ġ ����
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
     printf("���� �����̶�?\n");
     gotoxy(x - 2, y + 2);
     printf("���� ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰���\n\n");
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
     bubble_sort_with_steps(arr, n, x, y + 6);
     gotoxy(x - 2, y + 6 + n);
     printf("�Ϸ�� �迭 : ");
     print_array(arr, n);

     gotoxy(x - 2, y + 8 + n);
     printf("���� ���� �Ϸ�! �ƹ� Ű�� ������ ����ȭ������ ���ư��ϴ�.\n");
     _getch();  // ����� Ű �Է� ���
     return 0; 
}