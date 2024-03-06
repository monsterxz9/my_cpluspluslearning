//
// Created by Mark Tween on 2023/12/22.
//
#include <stdlib.h>
#include <stdio.h>

typedef char E;
struct TreeNode {
    E element;
    struct TreeNode *LNode;
    struct TreeNode *RNode;
    int flag;
};
typedef struct TreeNode* Node;
typedef Node T;
struct QueueNode{
    T element;
    struct QueueNode *next;

};
typedef struct QueueNode *QNode;
struct Queue{
    QNode front,rear;
};
typedef struct Queue* LinkedQueue;

_Bool initQueue(LinkedQueue queue)
{
    QNode node= malloc(sizeof(struct QueueNode));
    if(node==NULL)return 0;
    queue->front=queue->rear=node;
    return 1;
}
_Bool offerQueue(LinkedQueue queue,T element)
{
    QNode node= malloc(sizeof(struct QueueNode));
    if(node==NULL)return 0;
    node->element=element;
    queue->rear->next=node;
    queue->rear=node;
    return 1;
}
_Bool isEmpty(LinkedQueue queue)
{
    return queue->rear==queue->front;
}
T pollQueue(LinkedQueue queue)
{
    T e=queue->front->next->element;
    QNode node=queue->front->next;
    queue->front->next=queue->front->next->next;
    if(queue->rear==node)queue->rear=queue->front;
    free(node);
    return e;
}
void levelOrderTraversal(Node root)
{
    struct Queue queue;
    initQueue(&queue);
    offerQueue(&queue,root);
    while (!isEmpty(&queue)){
        Node node= pollQueue(&queue);
        printf("%c",node->element);
        if(node->LNode) offerQueue(&queue,node->LNode);
        if(node->RNode) offerQueue(&queue,node->RNode);
    }
}
int main() {
    Node a = malloc(sizeof(struct TreeNode));   //依次创建好这五个结点
    Node b = malloc(sizeof(struct TreeNode));
    Node c = malloc(sizeof(struct TreeNode));
    Node d = malloc(sizeof(struct TreeNode));
    Node e = malloc(sizeof(struct TreeNode));
    Node f = malloc(sizeof(struct TreeNode));
    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';
    f->element = 'F';
    a->LNode = b;
    a->RNode = c;
    b->LNode = d;
    b->RNode = e;
    c->LNode = f;
    c->RNode = NULL;
    d->LNode = d->RNode = NULL;
    e->LNode = e->RNode = NULL;
    f->LNode = f->RNode = NULL;
    levelOrderTraversal(a);
    return 0;
}