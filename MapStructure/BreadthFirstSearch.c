//
// Created by Mark Tween on 2023/12/26.
//
#define MaxVertex 7

#include <stdio.h>
#include <stdlib.h>

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

typedef int T;
struct QueueNode {
    T element;
    struct QueueNode *next;
};
typedef struct QueueNode *QNode;
struct Queue {
    QNode front, rear;
};
typedef struct Queue *LinkedQueue;

_Bool initQueue(LinkedQueue queue) {
    QNode node = malloc(sizeof(struct QueueNode));
    if (node == NULL)return 0;
    queue->rear = queue->front = node;
    return 1;
}

_Bool offerQueue(LinkedQueue queue, T element) {
    QNode node = malloc(sizeof(struct QueueNode));
    if (node == NULL)return 0;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

_Bool isEmpty(LinkedQueue queue) {
    return queue->rear == queue->front;
}

T pollQueue(LinkedQueue queue) {
    T e = queue->front->next->element;
    QNode node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if (queue->rear == node)queue->rear = queue->front;
    free(node);
    return e;
}

/*void bfs(Graph graph, int startVertex, int targetVertex, int *visited, LinkedQueue queue) {
    offerQueue(queue, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(queue)) {
        int current = pollQueue(queue);
        printf("%c", graph->vertex[current].element);
        if (current == targetVertex) break;  // 如果找到目标顶点，则停止搜索
        printf(" -> ");
        Node node = graph->vertex[current].next;
        while (node) {
            if (!visited[node->nextVertex]) {  // 使用正确的字段检查是否访问过
                offerQueue(queue, node->nextVertex);
                visited[node->nextVertex] = 1;
            }
            node = node->next;
        }
    }
    printf("\nEnd of Search");
}*/
_Bool bfs(Graph graph, int startVertex, int targetVertex, int *visited, LinkedQueue queue) {
    offerQueue(queue, startVertex);
    visited[startVertex] = 1;
    while (!isEmpty(queue)) {
        int next = pollQueue(queue);
        printf("%c -> ", graph->vertex[next].element);
        Node node = graph->vertex[next].next;
        while (node) {
            if (node->nextVertex == targetVertex) {
                printf("%c", graph->vertex[targetVertex].element);
                return 1;   //如果就是我们要找的，直接返回1
            }
            if (!visited[node->nextVertex]) {
                offerQueue(queue, node->nextVertex);
                visited[node->nextVertex] = 1;
            }
            node = node->next;
        }
    }
    free(queue);
    return 0;   //找完了还没有，那就返回0
}

int main() {
    Graph graph = create();
    for (int c = 'A'; c <= 'G'; ++c) {
        addVertex(graph, (char) c);
    }
    addEdge(graph, 0, 1);//A->B
    addEdge(graph, 1, 2);//B->C
    addEdge(graph, 1, 3);//B->D
    addEdge(graph, 1, 4);//B->E
    addEdge(graph, 4, 5);//E->F
    addEdge(graph, 3, 6);//D->G
    int arr[graph->vertexCount];
    for (int i = 0; i < graph->vertexCount; ++i) {
        arr[i] = 0;
    }
    struct Queue queue;
    initQueue(&queue);
    printf("\n%d", bfs(graph, 0, 6, arr, &queue));
    free(graph);
}