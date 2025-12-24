#include <stdio.h>

#define N 5

int graph[N][N] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 0, 1, 0}
};

int visited[N];

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < N; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int queue[N];
    int front = 0, rear = 0;

    for (int i = 0; i < N; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < N; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    printf("DFS Traversal: ");
    DFS(0);

    printf("\n");

    printf("BFS Traversal: ");
    BFS(0);

    return 0;
}
