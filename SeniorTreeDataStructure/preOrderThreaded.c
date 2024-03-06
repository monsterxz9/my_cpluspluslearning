#include <stdio.h>
#include <stdlib.h>


typedef char E;


typedef struct TreeNode {
    E element;
    struct TreeNode *left;
    struct TreeNode *right;
    int leftTag, rightTag;
} *Node;

Node createNode(E element) {
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->rightTag = node->leftTag = 0;
    node->element = element;
    return node;
}

Node pre = NULL;

void preOrderThreaded(Node root) {
    if (root == NULL)return;
    if (root->left == NULL) {
        root->left = pre;
        root->leftTag = 1;
    }
    if (pre && pre->right == NULL) {
        pre->right = root;
        pre->rightTag = 1;
    }
    pre = root;
    if (root->leftTag == 0) {
        preOrderThreaded(root->left);
    }
    if (root->rightTag== 0) {
        preOrderThreaded(root->right);
    }
}
void inOrder(Node root)
{
    while (root){
        printf("%c",root->element);
        if(root->leftTag==0)root=root->left;
        else root=root->right;
    }
}

int main() {
    Node a = createNode('A');
    Node b = createNode('B');
    Node c = createNode('C');
    Node d = createNode('D');
    Node e = createNode('E');
    a->left = b;
    b->left = d;
    a->right = c;
    b->right = e;
    preOrderThreaded(a);
    inOrder(a);
}
