//
// Created by Mark Tween on 2023/12/23.
//
#include <stdio.h>
#include <stdlib.h>

typedef char E;
typedef struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    struct TreeNode * parent;   //指向双亲（父）结点
    int leftTag, rightTag;
} * Node;

Node createNode(E element) {
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->rightTag = node->leftTag = 0;
    node->element = element;
    return node;
}

Node pre = NULL;  //这里我们需要一个pre来保存后续结点的指向
void postOrderThreaded(Node root){   //前序遍历线索化函数
    if(root == NULL) return;
    if(root->leftTag == 0) {
        postOrderThreaded(root->left);
        if(root->left) root->left->parent = root;  //左边完事之后，如果不为空，那么就设定父子关系
    }
    if(root->rightTag == 0) {
        postOrderThreaded(root->right);
        if(root->right) root->right->parent = root;   //右边完事之后，如果不为空，那么就设定父子关系
    }
    //------  线索化 -------
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
}
void postOrder(Node root){
    Node last = NULL, node = root;  //这里需要两个暂存指针，一个记录上一次遍历的结点，还有一个从root开始
    while (node) {
        while (node->left != last && node->leftTag == 0)    //依然是从整棵树最左边结点开始，和前面一样，只不过这里加入了防无限循环机制，看到下面就知道了
            node = node->left;
        while (node && node->rightTag == 1) {   //左边完了还有右边，如果右边是线索，那么直接一路向前，也是跟前面一样的
            printf("%c", node->element);   //沿途打印
            last = node;
            node = node->right;
        }
        if (node == root && node->right == last) {
            //上面的操作完成之后，那么当前结点左右就结束了，此时就要去寻找其兄弟结点了，我们可以
            //直接通过parent拿到兄弟结点，但是如果当前结点是根结点，需要特殊处理，因为根结点没有父结点了
            printf("%c", node->element);
            return;   //根节点一定是最后一个，所以说直接返回就完事
        }
        while (node && node->right == last) {    //如果当前结点的右孩子就是上一个遍历的结点，那么一直向前就行
            printf("%c", node->element);   //直接打印当前结点
            last = node;
            node = node->parent;
        }
        //到这里只有一种情况了，是从左子树上来的，那么当前结点的右边要么是线索要么是右子树，所以直接向右就完事
        if(node && node->rightTag == 0) {  //如果不是线索，那就先走右边，如果是，等到下一轮再说
            node = node->right;
        }
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
    postOrderThreaded(a);
    postOrder(a);
}
