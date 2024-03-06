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
struct TreeNode* createNode(int element)
{
    struct TreeNode* node= malloc(sizeof (struct TreeNode));
    node->left=node->right=NULL;
    node->val=element;
    return node;
}
struct TreeNode* buildTreeCore(int* preorder,int* inorder, int start,  int end,int index) {
    if(start>end)return NULL;
    if(start==end)return createNode(preorder[index]);
    struct TreeNode*node= createNode(preorder[index]);
    int pos=0;
    while (inorder[pos]!=preorder[index])pos++;
    node->left= buildTreeCore(preorder,inorder,start,pos-1,index-1);
    node->right= buildTreeCore(preorder,inorder,pos+1,end,index+(pos-start)+1);
    return node;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return buildTreeCore(preorder,inorder,0,preorderSize-1,0)
}