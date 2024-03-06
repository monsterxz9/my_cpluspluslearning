//
// Created by Mark Tween on 2023/12/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isValid(struct TreeNode *root, long min,long max) {
    if (root == NULL)return true;
    if (root->left != NULL && (root->left->val >= root-> val || root->left->val <= min))
        return false;
    if (root->right != NULL && (root->right->val <= root->val || root->right->val >= max))
        return false;
    return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
}

bool isValidBST(struct TreeNode *root) {
    return isValid(root, -2147483649, 2147483648);
}