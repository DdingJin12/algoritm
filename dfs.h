#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "bfs.h"
#define SIZE 40

typedef struct Stack {
    int items[SIZE];
    int top;
} Stack;

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

void push(Stack* stack, int value) {
    if (stack->top == SIZE - 1) {
        printf("Stack is Full");
    }
    else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is Empty");
        return -1;
    }
    else {
        int item = stack->items[stack->top];
        stack->top--;
        return item;
    }
}

int isEmptyStack(Stack* stack) {
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

// DFS algorithm
void dfs_graph(struct Graph* graph, int startVertex, int x, int y) {
    struct Stack* stack = createStack();
    int count = 0;

    push(stack, startVertex);

    while (!isEmptyStack(stack)) {
        int currentVertex = pop(stack);
        // Check if the current Node is visited
        if (graph->visited[currentVertex] == 0) {
            graph->visited[currentVertex] = 1;
            gotoxy(x - 2, y + 7 + count);  // Set cursor position
            printf("Visited %d: Node %d", count, currentVertex);
            count++;
        }

        Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                push(stack, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int dfs() {
    system("cls");
    int x = 5;
    int y = 2;
    gotoxy(x - 2, y);
    printf("DFS(���� �켱 Ž��) �̶�?");
    gotoxy(x - 2, y + 2);
    printf("��Ʈ ���(Ȥ�� �ٸ� ������ ���)���� �����ؼ� ���� �б�� �Ѿ�� ���� \n");
    gotoxy(x - 2, y + 3);
    printf("�ش� �б⸦ �Ϻ��ϰ� Ž���ϴ� ���");
    gotoxy(x - 2, y + 5);
    printf("DFS ����");
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);

    // dfs ȣ��
    dfs_graph(graph, 2, x, y);
    gotoxy(x - 2, y + 12);
    printf("DFS(���� �켱 Ž��) ���� �Ϸ�");
    _getch();  // Wait for user key input
    return 0;
}