//
// Created by Mark Tween on 2023/12/25.
//
#include "stdlib.h"
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int result = -2147483648;
int max(int a, int b) {
    return a > b ? a : b;
}
int maxValue(struct TreeNode *root) {
    if (root == NULL)return 0;
    int leftMax = max(maxValue(root->left), 0);
    int rightMax = max(maxValue(root->right), 0);
    int maxTmp = leftMax + rightMax + root->val;
    result = max(maxTmp, result);
    return max(leftMax, rightMax) + root->val;
}

int maxPathSum(struct TreeNode *root) {
    maxValue(root);
    return result;
}