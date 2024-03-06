#include <iostream>

// 定义树节点结构
struct TreeNode {
    int data; // 节点的数据
    TreeNode* firstChild; // 指向第一个子节点的指针
    TreeNode* nextSibling; // 指向下一个兄弟节点的指针
};

// 初始化树
void InitTree(TreeNode*& T) {
    T = nullptr; // 将树初始化为空
}

// 创建节点
TreeNode* CreateTreeNode(int value) {
    TreeNode* newNode = new TreeNode;
    newNode->data = value;
    newNode->firstChild = nullptr;
    newNode->nextSibling = nullptr;
    return newNode;
}

// 销毁树
void DestroyTree(TreeNode*& T) 
{
    if (T == nullptr) {
        return;
    }
    DestroyTree(T->firstChild); // 递归销毁子树
    DestroyTree(T->nextSibling); // 递归销毁兄弟节点
    delete T; // 删除当前节点
    T = nullptr;
}

int main() 
{
    TreeNode* treeRoot;
    InitTree(treeRoot); // 初始化树

    // 创建节点并构建树结构
    TreeNode* nodeA = CreateTreeNode(1);
    TreeNode* nodeB = CreateTreeNode(2);
    TreeNode* nodeC = CreateTreeNode(3);

    nodeA->firstChild = nodeB;
    nodeB->nextSibling = nodeC;

    treeRoot = nodeA; // 设置根节点

    // 执行其他树操作...

    // 销毁树
    DestroyTree(treeRoot);

    return 0;
}
