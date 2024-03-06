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

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode*newHead=NULL,*tmp;
    while (head){
        tmp=head->next;
        head->next=newHead;
        newHead=head;
        head=tmp;
    }
    return newHead;
}