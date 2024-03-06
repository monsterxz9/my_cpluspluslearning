//
// Created by Mark Tween on 2023/12/24.
//
#include "stdlib.h"
#include "stdlib.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumNumbersImpl(struct TreeNode *root, int parent) {
    if (root == NULL)return 0;
    int sum = root->val + parent * 10;
    if (!root->left && !root->right)return sum;
    return sumNumbersImpl(root->left, sum) + sumNumbersImpl(root->right, sum);
}

int sumNumbers(struct TreeNode *root) {
    return sumNumbersImpl(root, 0);
}