/**
 * File: linked_list.c
 * Created Time: 2023-01-12
 * Author: Zero (glj0@outlook.com)
 */

#include "../include/include.h"

/* ������Ľ�� n0 ֮������� P */
void insert(ListNode* n0, ListNode* P) {
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

/* ɾ������Ľ�� n0 ֮����׸���� */
// ���������� stdio.h ���˴��޷�ʹ�� remove �ؼ���
// ��� https://github.com/krahets/hello-algo/pull/244#discussion_r1067863888
void removeNode(ListNode* n0) {
    if (!n0->next)
        return;
    // n0 -> P -> n1
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    // �ͷ��ڴ�
    free(P);
}

/* ��������������Ϊ index �Ľ�� */
ListNode* access(ListNode* head, int index) {
    while (head && head->next && index) {
        head = head->next;
        index--;
    }
    return head;
}

/* �������в���ֵΪ target ���׸���� */
int find(ListNode* head, int target) {
    int index = 0;
    while (head) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}


/* Driver Code */
int main() {
    /* ��ʼ������ */
    // ��ʼ��������� 
    ListNode* n0 = newListNode(1);
    ListNode* n1 = newListNode(3);
    ListNode* n2 = newListNode(2);
    ListNode* n3 = newListNode(5);
    ListNode* n4 = newListNode(4);
    // ��������ָ��
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printf("��ʼ��������Ϊ\r\n"); 
    printLinkedList(n0);

    /* ������ */
    insert(n0, newListNode(0));
    printf("������������Ϊ\r\n");
    printLinkedList(n0);

    /* ɾ����� */
    removeNode(n0);
    printf("ɾ�����������Ϊ\r\n");
    printLinkedList(n0);

    /* ���ʽ�� */
    ListNode* node = access(n0, 3);
    printf("���������� 3 ���Ľ���ֵ = %d\r\n", node->val);

    /* ���ҽ�� */
    int index = find(n0, 2);
    printf("������ֵΪ 2 �Ľ������� = %d\r\n", index);

    return 0;
}
