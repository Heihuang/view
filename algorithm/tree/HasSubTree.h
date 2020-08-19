//题目：树的子结构，输入两颗二叉树A和B，判断B是不是A的子结构。
//第一步：在树A中查找与根结点的值一样的节点。
//第二步：判断树A中以R为根结点的子树是不是和树B具有相同的结构
#include "BInaryTree.h"

bool DoseTreeHaveTree2(BInaryTreeNode* proot1, BInaryTreeNode* proot2)
{
    if (proot2 == nullptr)
    {
        return true;
    }
    if (proot2 == nullptr)
    {
        return false;
    }
    if (proot1->value != proot2->value)
    {
        /* code */
        return false;
    }
    //分别判断左右子树是否同时相同
    return DoseTreeHaveTree2(proot1->left, proot2->left) && 
        DoseTreeHaveTree2(proot1->right, proot1->right);
}

bool HasSubTree(BInaryTreeNode* proot1, BInaryTreeNode* proot2)
{
    bool res = false;
    //找到A树中节点与B树相同的节点
    if (proot1->value == proot2->value)
    {
        /*判断子树*/
        res = DoseTreeHaveTree2(proot1, proot2);
    }
    if (!res)
    {
        res = HasSubTree(proot1->left, proot2);
    }
    if (!res)
    {
        res = HasSubTree(proot1->right, proot2);
    }
    
}