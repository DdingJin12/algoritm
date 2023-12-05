#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
#include "main.h"
#define V 5

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int n, int graph[V][V], int x, int y) {
    gotoxy(x, y);
    printf("Edge   Weight");
    for (int i = 1; i < V; i++) {
        gotoxy(x, y + i + 1);
        printf("%d - %d    %d ", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V], int x, int y) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);

        mstSet[u] = 1;

        for (int v = 0; v < V; v++)

            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, V, graph, x, y);
}

int prim() {
    int graph[V][V] = { {0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0} };
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("���� �˰��� �̶�?");
    gotoxy(x - 2, y + 2);
    printf("���� ������������ ����� ����Ʈ�� ������ �ܰ������� Ȯ���ϴ� �˰���");
    gotoxy(x - 2, y + 4);
    printf("���� �˰��� ����");
    gotoxy(x - 2, y + 6);
    primMST(graph, x, y + 7);

    gotoxy(x - 2, y + 14);
    printf("���� �˰��� ���� �Ϸ�! �ƹ� Ű�� ������ ����ȭ������ ���ư��ϴ�.");
    _getch();  // ����� Ű �Է� ���
    return 0;
}