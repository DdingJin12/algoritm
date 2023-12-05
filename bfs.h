#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#define SIZE 40

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

typedef struct Queue {
    int items[SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear == SIZE - 1)
        printf("Queue is Full\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

int isEmpty(Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// BFS algorithm
void bfs_graph(Graph* graph, int startVertex, int x, int y) {
    Queue* q = createQueue();
    int count = 0;

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        gotoxy(x - 2, y + 6 + count);  // Ŀ�� ��ġ ����
        int currentVertex = dequeue(q);
        printf("Visited %d: Node %d", count, currentVertex);
        count++;
        Node * temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int bfs() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("BFS(�ʺ� �켱 Ž��) �̶�?\n");
    gotoxy(x - 2, y + 2);
    printf("��Ʈ ���(Ȥ�� �ٸ� ������ ���)���� �����ؼ� ������ ��带 ���� Ž���ϴ� ���");
    gotoxy(x - 2, y + 4);
    printf("BFS ����");
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);

    // bfs ȣ��
    bfs_graph(graph, 2, x, y);
    gotoxy(x - 2, y + 11);
    printf("BFS(�ʺ� �켱 Ž��) ���� �Ϸ�! �ƹ� Ű�� ������ ����ȭ������ ���ư��ϴ�.\n");
    _getch();  // ����� Ű �Է� ���
    return 0;
}