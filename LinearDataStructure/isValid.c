#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char E;

struct LNode {
    E element;
    struct LNode * next;
};

typedef struct LNode * Node;

void initStack(Node head){
    head->next = NULL;
}

_Bool pushStack(Node head, E element){
    Node node = malloc(sizeof(struct LNode));
    if(node == NULL) return 0;
    node->next = head->next;
    node->element = element;
    head->next = node;
    return 1;
}

_Bool isEmpty(Node head){
    return head->next == NULL;
}

E popStack(Node head) {
    Node top = head->next;
    head->next = head->next->next;
    E e = top->element;
    free(top);
    return e;
}

_Bool isValid(char *s) {
    unsigned long len = strlen(s);
    if (len%2==1)return false;
    struct LNode head;
    initStack(&head);

    for (int i = 0; i < len; ++i) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            pushStack(&head, c);
        } else {
        if(isEmpty(&head)) return false;
            if (c == ')') {
                if (popStack(&head) != '(')return false;
            } else if (c == ']') {
                if (popStack(&head) != '[')return false;
            } else  {
                if (popStack(&head) != '{')return false;
            }
        }
    }
    return isEmpty(&head);
}

