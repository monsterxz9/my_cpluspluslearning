/*二叉树的前序遍历递归算法*/
/*初始条件二叉树T存在*/
/*操作结果:前序递归遍历T*/
#include <stdio.h>

// 定义二叉树节点的结构
typedef struct BiTreeNode 
{
    int data; // 节点的数据
    struct BiTreeNode* lchild; // 左子树节点指针
    struct BiTreeNode* rchild; // 右子树节点指针
} 
BiTreeNode, *BiTree;

// 前序遍历递归函数
void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    printf("%d ", T->data); // 显示结点数据，这里假设节点数据类型是整数
    PreOrderTraverse(T->lchild); // 先序遍历左子树
    PreOrderTraverse(T->rchild); // 先序遍历右子树
}

int main()
{
    // 创建二叉树节点示例
    BiTreeNode node1, node2, node3;
    node1.data = 1;
    node2.data = 2;
    node3.data = 3;

    // 构建树结构
    node1.lchild = &node2;
    node1.rchild = &node3;
    node2.lchild = node2.rchild = node3.lchild = node3.rchild = NULL;

    // 调用前序遍历函数
    PreOrderTraverse(&node1);

    return 0;
}
