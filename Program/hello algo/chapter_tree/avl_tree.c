/**
 * File: avl_tree.c
 * Created Time: 2023-01-15
 * Author: Reanon (793584285 @ qq.com)
 */

#include "../include/include.h"

/* AVL Tree */
struct avlTree {
    TreeNode *root;
};

typedef struct avlTree avlTree;

/* ���� AVL �� */
avlTree *newAVLTree() {
    avlTree *tree = (avlTree *) malloc(sizeof(avlTree));
    tree->root = NULL;
    return tree;
}

int height(TreeNode *node) {
    // �ս��߶�Ϊ -1 ��Ҷ���߶�Ϊ 0
    if (node != NULL) {
        return node->height;
    }
    return -1;
}

/* ���½��߶� */
void updateHeight(TreeNode *node) {
    int lh = height(node->left);
    int rh = height(node->right);
    // ���߶ȵ�����������߶� + 1
    if (lh > rh) {
        node->height = lh + 1;
    } else {
        node->height = rh + 1;
    }
}

/* ��ȡƽ������ */
int balanceFactor(TreeNode *node) {
    // �ս��ƽ������Ϊ 0
    if (node == NULL) {
        return 0;
    }
    // ���ƽ������ = �������߶� - �������߶�
    return height(node->left) - height(node->right);
}

/* �������� */
TreeNode *rightRotate(TreeNode *node) {
    TreeNode *child, *grandChild;
    child = node->left;
    grandChild = child->right;
    // �� child Ϊԭ�㣬�� node ������ת
    child->right = node;
    node->left = grandChild;
    // ���½��߶�
    updateHeight(node);
    updateHeight(child);
    // ������ת�������ĸ����
    return child;
}

/* �������� */
TreeNode *leftRotate(TreeNode *node) {
    TreeNode *child, *grandChild;
    child = node->right;
    grandChild = child->left;
    // �� child Ϊԭ�㣬�� node ������ת
    child->left = node;
    node->right = grandChild;
    // ���½��߶�
    updateHeight(node);
    updateHeight(child);
    // ������ת�������ĸ����
    return child;
}

/* ִ����ת������ʹ���������»ָ�ƽ�� */
TreeNode *rotate(TreeNode *node) {
    // ��ȡ��� node ��ƽ������
    int bf = balanceFactor(node);
    // ��ƫ��
    if (bf > 1) {
        if (balanceFactor(node->left) >= 0) {
            // ����
            return rightRotate(node);
        } else {
            // ������������
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    // ��ƫ��
    if (bf < -1) {
        if (balanceFactor(node->right) <= 0) {
            // ����
            return leftRotate(node);
        } else {
            // ������������
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    // ƽ������������ת��ֱ�ӷ���
    return node;
}

/* �ݹ�����㣨���������� */
TreeNode *insertHelper(TreeNode *node, int val) {
    if (node == NULL) {
        return newTreeNode(val);
    }
    /* 1. ���Ҳ���λ�ã��������� */
    if (val < node->val) {
        node->left = insertHelper(node->left, val);
    } else if (val > node->val) {
        node->right = insertHelper(node->right, val);
    } else {
        // �ظ���㲻���룬ֱ�ӷ���
        return node;
    }
    // ���½��߶�
    updateHeight(node);
    /* 2. ִ����ת������ʹ���������»ָ�ƽ�� */
    node = rotate(node);
    // ���������ĸ����
    return node;
}


/* ������ */
TreeNode *insert(avlTree *tree, int val) {
    tree->root = insertHelper(tree->root, val);
    return tree->root;
}

/* ��ȡ��������е���һ����㣨�������� root �����ӽ�������� */
TreeNode *getInOrderNext(TreeNode *node) {
    if (node == NULL) {
        return node;
    }
    // ѭ���������ӽ�㣬ֱ��Ҷ���ʱΪ��С��㣬����
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

/* �ݹ�ɾ����㣨���������� */
TreeNode *removeHelper(TreeNode *node, int val) {
    TreeNode *child, *grandChild, *temp;
    if (node == NULL) {
        return NULL;
    }
    /* 1. ���ҽ�㣬��ɾ��֮ */
    if (val < node->val) {
        node->left = removeHelper(node->left, val);
    } else if (val > node->val) {
        node->right = removeHelper(node->right, val);
    } else {
        if (node->left == NULL || node->right == NULL) {
            child = node->left;
            if (node->right != NULL) {
                child = node->right;
            }
            // �ӽ������ = 0 ��ֱ��ɾ�� node ������
            if (child == NULL) {
                return NULL;
            } else {
                // �ӽ������ = 1 ��ֱ��ɾ�� node
                node = child;
            }
        } else {
            // �ӽ������ = 2 ��������������¸����ɾ�������øý���滻��ǰ���
            temp = getInOrderNext(node->right);
            node->right = removeHelper(node->right, temp->val);
            node->val = temp->val;
        }
    }
    // ���½��߶�
    updateHeight(node);
    /* 2. ִ����ת������ʹ���������»ָ�ƽ�� */
    node = rotate(node);
    // ���������ĸ����
    return node;
}

/* ɾ����� */
// ���������� stdio.h ���˴��޷�ʹ�� remove �ؼ���
TreeNode *removeNode(avlTree *tree, int val) {
    TreeNode *root = removeHelper(tree->root, val);
    return root;
}

/* ���ҽ�� */
TreeNode *search(avlTree *tree, int val) {
    TreeNode *cur = tree->root;
    // ѭ�����ң�Խ��Ҷ��������
    while (cur != NULL) {
        if (cur->val < val) {
            // Ŀ������ cur ����������
            cur = cur->right;
        } else if (cur->val > val) {
            // Ŀ������ cur ����������
            cur = cur->left;
        } else {
            // �ҵ�Ŀ���㣬����ѭ��
            break;
        }
    }
    // �ҵ�Ŀ���㣬����ѭ��
    return cur;
}

void testInsert(avlTree *tree, int val) {
    insert(tree, val);
    printf("\n������ %d ��AVL ��Ϊ \n", val);
    printTree(tree->root);
}

void testRemove(avlTree *tree, int val) {
    removeNode(tree, val);
    printf("\nɾ����� %d ��AVL ��Ϊ \n", val);
    printTree(tree->root);
}

/* Driver Code */
int main() {
    /* ��ʼ���� AVL �� */
    avlTree *tree = (avlTree *) newAVLTree();
    /* ������ */
    // ���ע�������AVL ������α���ƽ���
    testInsert(tree, 1);
    testInsert(tree, 2);
    testInsert(tree, 3);
    testInsert(tree, 4);
    testInsert(tree, 5);
    testInsert(tree, 8);
    testInsert(tree, 7);
    testInsert(tree, 9);
    testInsert(tree, 10);
    testInsert(tree, 6);

    /* �����ظ���� */
    testInsert(tree, 7);

    /* ɾ����� */
    // ���עɾ������AVL ������α���ƽ���
    testRemove(tree, 8); // ɾ����Ϊ 0 �Ľ��
    testRemove(tree, 5); // ɾ����Ϊ 1 �Ľ��
    testRemove(tree, 4); // ɾ����Ϊ 2 �Ľ��

    /* ��ѯ��� */
    TreeNode *node = search(tree, 7);
    printf("\n���ҵ��Ľ�������ֵ = %d \n", node->val);

}