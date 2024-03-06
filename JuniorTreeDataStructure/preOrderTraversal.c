//
// Created by Mark Tween on 2023/12/22.
//
#include <stdlib.h>
#include <stdio.h>

typedef char E;
typedef struct TreeNode {
    E element;
    struct TreeNode *LNode;
    struct TreeNode *RNode;
} *Node;
//------------- 栈 -------------------
typedef Node T;   //这里栈内元素类型定义为上面的Node，也就是二叉树结点指针

struct StackNode {
    T element;
    struct StackNode * next;
};
typedef struct StackNode * SNode;  //这里就命名为SNode，不然跟上面冲突了就不好了
void initStack(SNode head){
    head->next = NULL;
}

_Bool pushStack(SNode head, T element){
    SNode node = malloc(sizeof(struct StackNode));
    if(node == NULL) return 0;
    node->next = head->next;
    node->element = element;
    head->next = node;
    return 1;
}

_Bool isEmpty(SNode head){
    return head->next == NULL;
}

T popStack(SNode head){
    SNode top = head->next;
    head->next = head->next->next;
    T e = top->element;
    free(top);
    return e;
}
void preOrderStack(Node root)
{
    struct StackNode head;
    initStack(&head);
    while (root || !isEmpty(&head)) {
        while (root) {
            printf("%c", root->element);
            pushStack(&head, root);
            root = root->LNode;
        }
        Node node= popStack(&head);
        root=node->RNode;
    }
}

void preOrderRecursion(Node root) {
    if (root == NULL)return;
    printf("%c ", root->element);
    preOrderRecursion(root->LNode);
    preOrderRecursion(root->RNode);
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
    preOrderRecursion(a);
    preOrderStack(a);
    return 0;
}