//
// Created by Mark Tween on 2023/12/23.
//
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

Node pre = NULL;  //这里我们需要一个pre来保存后续结点的指向
void inOrderThreaded(Node root){   //前序遍历线索化函数
    if(root == NULL) return;
    if(root->leftTag == 0)
        inOrderThreaded(root->left);

    //------  线索化 -------  现在放到中间去，其他的还是一样的
    if(root->left == NULL) {
        root->left = pre;
        root->leftTag = 1;
    }
    if(pre && pre->right == NULL) {
        pre->right = root;
        pre->rightTag = 1;
    }
    pre = root;
    //--------------------

    if(root->rightTag == 0)
        inOrderThreaded(root->right);
}

void inOrder(Node root){
    while (root) {   //因为中序遍历需要先完成左边，所以说要先走到最左边才行
        while (root && root->leftTag == 0)    //如果左边一直都不是线索，那么就一直往左找，直到找到一个左边是线索的为止，表示到头了
            root = root->left;

        printf("%c", root->element);   //到最左边了再打印，中序开始

        while (root && root->rightTag == 1) {   //打印完就该右边了，右边如果是线索化之后的结果，表示是下一个结点，那么就一路向前，直到不是为止
            root = root->right;
            printf("%c", root->element);   //注意按着线索往下就是中序的结果，所以说沿途需要打印
        }
        root = root->right;  //最后继续从右结点开始，重复上述操作
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
    inOrderThreaded(a);
    inOrder(a);
}
