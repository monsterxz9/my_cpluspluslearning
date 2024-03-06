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
    int flag;
} *Node;
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
T peekStack(SNode head) {
    return head->next->element;
}
/*
void postOrderTraversalStack(Node root) {
    if (root == NULL) return;

    struct StackNode s1, s2;
    initStack(&s1);
    initStack(&s2);

    pushStack(&s1, root);
    Node node;

    while (!isEmpty(&s1)) {
        node = popStack(&s1);
        pushStack(&s2, node);

        if (node->LNode != NULL)
            pushStack(&s1, node->LNode);
        if (node->RNode != NULL)
            pushStack(&s1, node->RNode);
    }

    while (!isEmpty(&s2)) {
        node = popStack(&s2);
        printf("%c ", node->element);
    }
}
*/
void postOrderTraversalStack(Node root){
    struct StackNode stack;
    initStack(&stack);
    while (root || !isEmpty(&stack)){   //其他都不变
        while (root) {
            pushStack(&stack, root);
            root->flag = 0;    //首次入栈时，只能代表左子树遍历完成，所以flag置0
            root = root->LNode;
        }
        root = peekStack(&stack);   //注意这里只是获取到结点，并没有进行出栈操作，因为需要等待右子树遍历完才能出栈
        if(root->flag == 0) {    //如果仅仅遍历了左子树，那么flag就等于0
            root->flag = 1;   //此时标记为1表示遍历右子树
            root = root->RNode;   //这里跟之前是一样的
        } else {
            printf("%c ", root->element);   //当flag为1时走这边，此时左右都遍历完成了，这时再打印值出来
            popStack(&stack);   //这时再把对应的结点出栈，因为左右都完事了
            root = NULL;   //置为NULL，下一轮直接跳过while，然后继续取栈中剩余的结点，重复上述操作
        }
    }
}
void postOrderTraversalRecursion(Node root)
{
    if (root==NULL)return;
    postOrderTraversalRecursion(root->LNode);
    postOrderTraversalRecursion(root->RNode);
    printf("%c ",root->element);
}

int main() {
    Node a = malloc(sizeof(struct TreeNode));
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
    postOrderTraversalRecursion(a);
    printf("\n");
    postOrderTraversalStack(a);
    return 0;
}