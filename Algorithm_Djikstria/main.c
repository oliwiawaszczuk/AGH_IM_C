#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF INT_MAX

void dijkstra(int vertices, int matrix[MAX_VERTICES][MAX_VERTICES], int start) {
    bool visited[MAX_VERTICES];
    int distance[MAX_VERTICES];

    for (int i = 0; i < vertices; i++) {
        distance[i] = INF;
        visited[i] = false;
    }
    distance[start] = 0;

    for (int i = 0; i < vertices-1; i++) {
        // szukanie wierzcholka o najmniejszej dlugosci, który nie został jeszcze odwiedzony
        int min = INF, vertex = -1;
        for (int j = 0; j < vertices; j++) {
            if (!visited[j] && distance[j] < min) {
                min = distance[j];
                vertex = j;
            }
        }
        if (vertex == -1) // jesli nie ma wierzcholka to skip
            break;
        visited[vertex] = true;

        for (int j = 0; j < vertices; j++)
            if (!visited[j] && matrix[vertex][j] && distance[vertex] != INF && distance[vertex] + matrix[vertex][j] < distance[j])
                distance[j] = distance[vertex] + matrix[vertex][j];
    }

    printf("Wierzchołek     Odległość od startu\n");
    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INF)
            printf("%d     Brak trasy\n", i);
        else
            printf("%d     %d\n", i, distance[i]);
    }
}

int main() {
    int vertices;
    printf("Podaj liczbe wierzcholkow w grafie: ");
    scanf("%d", &vertices);

    // Dynamic alocation
    // int **matrix = (int **)malloc(vertices * sizeof(int *));
    // for (int i = 0; i < vertices; i++) {
    //     matrix[i] = (int *)malloc(vertices * sizeof(int));
    // }

    int matrix[MAX_VERTICES][MAX_VERTICES];

    printf("Podaj macierz sasiedztwa (wagi krawedzi, 0 oznacza brak krawedzi):");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int start;
    printf("Podaj wierzcholek poczatkowy: ");
    scanf("%d", &start);

    dijkstra(vertices, matrix, start);

    // for (int i = 0; i < vertices; i++) {
    //     free(matrix[i]);
    // }
    // free(matrix);
    return 0;
}
