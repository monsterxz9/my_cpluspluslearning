#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTEX 5 // 假设最多有5个顶点

typedef struct {
    char vertices[MAX_VERTEX]; // 顶点集合
    int matrix[MAX_VERTEX][MAX_VERTEX]; // 邻接矩阵表示边
    int numVertices; // 当前图中的顶点数量
} Graph;

// 初始化图
void initGraph(Graph *G) {
    G->numVertices = 0;
    for (int i = 0; i < MAX_VERTEX; i++) {
        G->vertices[i] = '\0'; // 初始化顶点集合为空
        for (int j = 0; j < MAX_VERTEX; j++) {
            G->matrix[i][j] = 0; // 初始化邻接矩阵
        }
    }
}

// 添加顶点到图
void addVertex(Graph *G, char v) {
    if (G->numVertices < MAX_VERTEX) {
        G->vertices[G->numVertices++] = v;
    } else {
        printf("图已满，无法添加更多顶点\n");
    }
}

// 添加边到图
void addEdge(Graph *G, char v1, char v2) {
    int index1 = -1, index2 = -1;
    for (int i = 0; i < G->numVertices; i++) {
        if (G->vertices[i] == v1) {
            index1 = i;
        }
        if (G->vertices[i] == v2) {
            index2 = i;
        }
    }
    if (index1 != -1 && index2 != -1) {
        G->matrix[index1][index2] = 1; // 在邻接矩阵中表示边
        G->matrix[index2][index1] = 1; // 如果是无向图，添加对称边
    } else {
        printf("顶点不存在，无法添加边\n");
    }
}

// 深度优先遍历
void DFS(Graph *G, int vertex, bool visited[]) {
    printf("%c ", G->vertices[vertex]);
    visited[vertex] = true;

    for (int i = 0; i < G->numVertices; i++) {
        if (G->matrix[vertex][i] == 1 && !visited[i]) {
            DFS(G, i, visited);
        }
    }
}

// 对图进行深度优先遍历
void DFSTraverse(Graph *G) {
    bool visited[MAX_VERTEX] = {false};

    printf("深度优先遍历结果: ");
    for (int i = 0; i < G->numVertices; i++) {
        if (!visited[i]) {
            DFS(G, i, visited);
        }
    }
    printf("\n");
}

int main() {
    Graph G;
    initGraph(&G);

    addVertex(&G, 'A');
    addVertex(&G, 'B');
    addVertex(&G, 'C');
    addVertex(&G, 'D');
    addVertex(&G, 'E');

    addEdge(&G, 'A', 'B');
    addEdge(&G, 'A', 'C');
    addEdge(&G, 'B', 'D');
    addEdge(&G, 'C', 'E');
    addEdge(&G, 'D', 'E');

    DFSTraverse(&G);

    return 0;
}
