//
// Created by Mark Tween on 2023/12/26.
//
#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 6
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

/**
 *
 * @param graph
 * @param a
 * @param b
 */
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

/**
 *
 * @param graph
 */
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

/**
 *深度优先搜索
 * @param graph 图
 * @param starVertex 起点
 * @param targetVertex 目标点
 * @param visited 已访问数据
 */
_Bool dfs(Graph graph, int starVertex, int targetVertex, int *visited) {
    printf("%c -> ", graph->vertex[starVertex].element);
    visited[starVertex] = 1;
    if (starVertex == targetVertex)return 1;
    Node node = graph->vertex[starVertex].next;
    while (node) {
        if (!visited[node->nextVertex])
            if (dfs(graph, node->nextVertex, targetVertex, visited))
                return 1;
        node = node->next;
    }
    return 0;
}

int main() {
    Graph graph = create();
    for (int c = 'A'; c <= 'F'; ++c) {
        addVertex(graph, (char) c);
    }
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 4, 5);
    int arr[graph->vertexCount];
    for (int i = 0; i < graph->vertexCount; ++i) {
        arr[i] = 0;
    }
    printf("\n%d", dfs(graph, 0, 5, arr));

    free(graph);

}
