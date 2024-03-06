//
// Created by Mark Tween on 2023/12/21.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int E;
struct LNode {
    E element;
    struct LNode *next;
};
typedef struct LNode *Node;
struct Queue {
    Node front, rear;
};
typedef struct Queue *LinkedQueue;

_Bool initQueue(LinkedQueue queue) {
    Node node = malloc(sizeof(struct LNode));
    if (node == NULL) return 0;
    queue->rear = queue->front = node;
    queue->rear = node;
    return 1;
}

bool isEmpty(LinkedQueue queue) {
    return queue->rear == queue->front;
}

E pollQueue(LinkedQueue queue) {
    Node tmp =queue->front->next;
    E e =tmp->element;
    queue->front->next=queue->front->next->next;
    if(queue->rear==tmp) queue->rear=queue->front;
    free(tmp);
    return e;
}

bool offerQueue(LinkedQueue queue, E element) {
    Node node = malloc(sizeof(struct LNode));
    if (node == NULL) return 0;
    node->element = element;
    node->next = NULL;  // 初始化 next 指针
    queue->rear->next = node;
    queue->rear = node;  // 更新 rear 指针
    return 1;
}

void printQueue(LinkedQueue queue){
    printf("<<< ");
    Node node = queue->front->next;
    while (1) {    //注意不能直接判空，因为前面我们没考虑，也就没将新结点next设定为NULL
        printf("%d ", node->element);
        if(node == queue->rear) break;    //当已经打印最后一个元素后，再结束
        else node = node->next;
    }
    printf("<<<\n");
}
int main() {
    struct Queue queue;
    initQueue(&queue);
    for (int i = 0; i < 5; ++i) {
        offerQueue(&queue,i*100);
    }
    printQueue(&queue);
    while (!isEmpty(&queue))
    {
        printf("%d ", pollQueue(&queue));
    }
}