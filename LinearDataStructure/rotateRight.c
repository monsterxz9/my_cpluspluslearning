//
// Created by Mark Tween on 2023/12/21.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k) {
    if (head == NULL || k == 0) return head;
    int lenth = 1;
    struct ListNode *node = head;
    while (node->next) {
        node = node->next;
        lenth++;
    }
    if (lenth == k) return head;
    node->next = head;
    int i = lenth - k % lenth;
    while (--i)head = head->next;
    struct ListNode *res=head->next;
    head->next=NULL;
    return res;
}