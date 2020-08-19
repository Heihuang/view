#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <stdio.h>

struct BInaryTreeNode
{
    /* data */
    int value;
    BInaryTreeNode* left;
    BInaryTreeNode* right;
};
//前序
void PreOrderTraverse(BInaryTreeNode* root)
{
    if (root == nullptr)
    {
        /* code */
        return;
    }
    printf("v=%d", root->value);
    PreOrderTraverse(root->left);
    PreOrderTraverse(root->right);
}
//中序
void PreOrderTraverse(BInaryTreeNode* root)
{
    if (root == nullptr)
    {
        /* code */
        return;
    }
    PreOrderTraverse(root->left);
    printf("v=%d", root->value);
    PreOrderTraverse(root->right);
}
//后序  
void PreOrderTraverse(BInaryTreeNode* root)
{
    if (root == nullptr)
    {
        /* code */
        return;
    }
    printf("v=%d", root->value);
    PreOrderTraverse(root->left);
    PreOrderTraverse(root->right);
}
#endif