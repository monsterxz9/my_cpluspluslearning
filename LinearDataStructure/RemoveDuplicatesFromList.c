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
struct ListNode* deleteDuplicates(struct ListNode* head) {

    struct ListNode *node=head;
    while (node->next!=NULL)
    {
        if (node->val==node->next->val) {
            node->next = node->next->next;
        } else{
            node=node->next;
        }
    }
    return head;
}