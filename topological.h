#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define MAX_VERTICES 50

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1;
int rear = -1;

void init2(GraphType* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
}

void enqueue2(int v) {
    if (rear == MAX_VERTICES - 1) {
        fprintf(stderr, "큐가 포화상태입니다");
        return;
    }
    queue[++rear] = v;
}

int dequeue2() {
    if (front == rear) {
        fprintf(stderr, "큐가 공백상태입니다");
        return -1;
    }
    return queue[++front];
}

void topology_sort(GraphType* g) {
    int i, j, k;
    int in_degree[MAX_VERTICES] = { 0, };

    for (i = 0; i < g->n; i++)
        for (j = 0; j < g->n; j++)
            if (g->adj_mat[j][i] == 1)
                in_degree[i]++;

    for (i = 0; i < g->n; i++)
        if (in_degree[i] == 0)
            enqueue2(i);

    while (front != rear) {
        j = dequeue2();
        if (j != -1) {
            printf("정점 %d -> ", j);
            for (k = 0; k < g->n; k++)
                if (g->adj_mat[j][k] == 1 && --in_degree[k] == 0)
                    enqueue2(k);
        }
    }
    printf("\n");
}
int topological() {
    GraphType g;
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("위상 정렬이란?");
    gotoxy(x - 2, y + 2);
    printf("유향 그래프의 꼭짓점들을 변의 방향을 거스르지 않도록 나열하는 알고리즘");
    init2(&g);
    for (int i = 0; i < 6; i++)
        insert_vertex(&g, i);
    insert_edge(&g, 0, 2);
    insert_edge(&g, 0, 3);
    insert_edge(&g, 1, 3);
    insert_edge(&g, 1, 4);
    insert_edge(&g, 2, 3);
    insert_edge(&g, 2, 5);
    insert_edge(&g, 3, 5);
    insert_edge(&g, 4, 5);
    gotoxy(x - 2, y + 4);
    printf("위상 정렬 구현\n");
    gotoxy(x - 2, y + 6);
    topology_sort(&g);

    gotoxy(x - 2, y + 8);
    printf("위상 정렬 완료! 아무 키나 누르면 메인화면으로 돌아갑니다.");
    _getch();  // 사용자 키 입력 대기
    return 0;
}