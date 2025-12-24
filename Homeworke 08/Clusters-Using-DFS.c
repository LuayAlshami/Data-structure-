#include <stdio.h>

#define N 5

int graph[N][N] = {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0}
};

int visited[N] = {0};

void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < N; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int clusterCount = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Cluster %d: ", clusterCount);
            dfs(i);
            printf("\n");
        }
    }

    printf("Total number of clusters: %d\n", clusterCount);

    return 0;
}
