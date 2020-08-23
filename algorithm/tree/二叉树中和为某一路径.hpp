/*
题目：输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径，从树的根结点开始往下一直到叶节点
所经过的节点形成一条路径。
解法：当前序遍历的方式访问到某个节点时，我们把该节点添加到路径上，并累加该节点的值，如果该节点为叶节点并且路径中节点
的刚好等于输入的整数，则当前路径符合要求。如果当前节点不是叶子节点，则继续访问它的子节点。当前节点访问结束后，递归函数
将自动回到它的父节点，因此在函数退出之前要在路径上删除当前节点并减去当前节点的值，以确保返回父节点时路径刚好是从根结点
到父节点的路径
*/

#include "BInaryTree.h"
#include <vector>
#include <stdio.h>

void FindPath(BInaryTreeNode* root, int expsum, std::vector<int>& path, int& currentsum)
{
    currentsum += root->value;
    path.push_back(root->value);
    //如果是叶节点，并且路径上节点的和等于输入的值
    //打印这条路径
    bool isleaf = root->left == nullptr && root->right == nullptr;
    if (currentsum == expsum && isleaf)
    {
        //打印
        printf("A path is found: ");
        for (auto it:path)
        {
            /* code */
            printf("%d", it);
        }
        printf("\n");
    }
    //如果不是叶子节点，则遍历它的子节点
    if (root->left != nullptr)
    {
        FindPath(root->left, expsum, path, currentsum);
    }
    if (root->right != nullptr)
    {
        FindPath(root->right, expsum, path, currentsum);
    }
    //在返回父节点之前，在路径上删除当前节点
    //并在currentsum减去当前节点
    currentsum -= root->value;
    path.pop_back();
    
}