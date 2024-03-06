#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 5
typedef char E;
typedef struct MatrixGraph {
    int vertexCount;
    int edgeCount;
    int matrix[MaxVertex][MaxVertex];
    __attribute__((unused)) E data[MaxVertex];
} *Graph;

Graph create() {
    Graph graph = malloc(sizeof(struct MatrixGraph));
    graph->vertexCount = 0;
    graph->edgeCount = 0;
    for (int i = 0; i < MaxVertex; ++i) {
        for (int j = 0; j < MaxVertex; ++j) {
            graph->matrix[i][j] = 0;
        }
    }
    return graph;
}

void addVertex(Graph graph, E element) {
    if (graph->vertexCount >= MaxVertex)return;
    graph->data[graph->vertexCount++] = element;
}

void addEdge(Graph graph, int a, int b) {
    if (graph->matrix[a][b] == 0) {
        graph->matrix[a][b] = 1;
        graph->edgeCount++;
    }
}

void printGraph(Graph graph) {
    for (int i = -1; i < graph->vertexCount; ++i) {
        for (int j = -1; j < graph->vertexCount; ++j) {
            if (j == -1)
                printf("%c", 'A' + i);
            else if (i == -1)
                printf("%3c", 'A' + j);
            else
                printf("%3d", graph->matrix[i][j]);
        }
        putchar('\n');
    }
}

void freeGraph(Graph graph) {
    free(graph);
}

int main() {
    Graph graph = create();
    for (int c = 'A'; c <= 'D'; ++c) {
        addVertex(graph, (char) c);
        addEdge(graph, 0, 1);
        addEdge(graph, 1, 2);
        addEdge(graph, 2, 3);
        addEdge(graph, 3, 0);
        addEdge(graph, 2, 0);
    }
    printGraph(graph);
    freeGraph(graph);
}