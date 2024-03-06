//
// Created by Mark Tween on 2023/12/17.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode *newListNode(int val) {
    ListNode *node, *next;
    node = (ListNode *) malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void insertList(ListNode *n0, ListNode *P) {
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

void removeItem(ListNode *n0) {
    if (!n0->next)return;
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    free(P);
}

ListNode *access(ListNode *head, int index) {
    while (head && head->next && index) {
        head = head->next;
        index--;
    }
    return head;
}

int main() {
    ListNode *n0 = newListNode(1);
    ListNode *n1 = newListNode(3);
    ListNode *n2 = newListNode(2);
    ListNode *n3 = newListNode(5);
    ListNode *n4 = newListNode(4);
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    return 0;
}
