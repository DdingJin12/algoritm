#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    Edge* edges;
    int n;
} EdgeList;

int compare(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int i, int j) {
    int a = find(parent, i);
    int b = find(parent, j);
    parent[a] = b;
}

void Kruskal(EdgeList* el) {
    qsort(el->edges, el->n, sizeof(Edge), compare);

    int* parent = (int*)malloc(el->n * sizeof(int));
    for (int i = 0; i < el->n; i++)
        parent[i] = i;

    EdgeList* answer = (EdgeList*)malloc(sizeof(EdgeList));
    answer->edges = (Edge*)malloc(el->n * sizeof(Edge));
    answer->n = 0;

    for (int i = 0; i < el->n; i++) {
        int u = el->edges[i].u;
        int v = el->edges[i].v;

        if (find(parent, u) != find(parent, v)) {
            Union(parent, u, v);
            answer->edges[answer->n++] = el->edges[i];
        }
    }

    for (int i = 0; i < answer->n; i++)
    printf("Edge %d-%d: %d", answer->edges[i].u, answer->edges[i].v, answer->edges[i].w);

    free(parent);
    free(answer->edges);
    free(answer);
}

int kruskal() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("크루스칼 알고리즘이란?\n");
    gotoxy(x - 2, y + 2);
    printf("최소한의 비용으로 만들 수 있는 최소 신장 트리를 찾는 알고리즘\n");
    gotoxy(x - 2, y + 4);
    EdgeList el;
    el.edges = (Edge*)malloc(7 * sizeof(Edge));
    el.n = 7;

    el.edges[0].u = 0; el.edges[0].v = 1; el.edges[0].w = 7;
    el.edges[1].u = 0; el.edges[1].v = 3; el.edges[1].w = 5;
    el.edges[2].u = 1; el.edges[2].v = 2; el.edges[2].w = 8;
    el.edges[3].u = 1; el.edges[3].v = 3; el.edges[3].w = 9;
    el.edges[4].u = 1; el.edges[4].v = 4; el.edges[4].w = 7;
    el.edges[5].u = 2; el.edges[5].v = 4; el.edges[5].w = 5;
    el.edges[6].u = 3; el.edges[6].v = 4; el.edges[6].w = 15;

    Kruskal(&el);

    free(el.edges);
    gotoxy(x - 2, y + 6);
    printf("크루스칼 구현 완료! 아무 키나 누르면 메인화면으로 돌아갑니다.\n");
    _getch();  // 사용자 키 입력 대기
    return 0;
}