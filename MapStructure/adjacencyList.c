//
// Created by Mark Tween on 2023/12/26.
//
#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 5
typedef char E;
typedef struct Node {
    int nextVertex;
    struct Node *next;
} *Node;
struct HeadNode {
    E element;
    struct Node *next;
};
typedef struct AdjacencyGraph {
    int vertexCount;
    int edgeCount;
    struct HeadNode vertex[MaxVertex];
} *Graph;

Graph create() {
    Graph graph = malloc(sizeof(struct AdjacencyGraph));
    if (graph == NULL)return NULL;
    graph->vertexCount = graph->edgeCount = 0;
    return graph;
}

void addVertex(Graph graph, E element) {
    if (graph->vertexCount >= MaxVertex)return;
    graph->vertex[graph->vertexCount].element = element;
    graph->vertex[graph->vertexCount].next = NULL;
    graph->vertexCount++;
}

void addEdge(Graph graph, int a, int b) {
    Node node = graph->vertex[a].next;
    Node newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->nextVertex = b;
    if (!node) {
        graph->vertex[a].next = newNode;
    } else {
        do {
            if (node->nextVertex == b)return;
            if (node->next) node = node->next;
            else break;
        } while (1);
        node->next = newNode;
    }
    graph->edgeCount++;
}

void printGraph(Graph graph) {
    for (int i = 0; i < graph->vertexCount; ++i) {
        printf("%d | %c", i, graph->vertex[i].element);
        Node node = graph->vertex[i].next;
        while (node) {
            printf(" -> %d", node->nextVertex);
            node = node->next;
        }
        putchar('\n');
    }
}

int main() {
    Graph graph = create();
    for (int c = 'A'; c <= 'D'; ++c) {
        addVertex(graph, (char) c);
    }
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);
    addEdge(graph, 2, 0);
    printGraph(graph);
    free(graph);
}