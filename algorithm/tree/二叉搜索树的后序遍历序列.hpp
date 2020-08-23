//题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是返回true
//解题要点：在后序遍历得到的序列中，最后一个数字是树的根结点值，数组前面的分为部分：第一部分是左子树的值，比根结点小
//第二部分是右子树的值，比根结点大
#include "BInaryTree.h"

bool VerifySquenceofBST(int sq[], int len)
{
    if (sq == nullptr || len < 0)
    {
        return false;
    }
    //找到root
    int root = sq[len - 1];
    //BST中左节点都小于根结点
    int i = 0;
    for ( i = 0; i < len - 1; i++)
    {
        if (sq[i] > root)
        {
            break;
        } 
    }
    //BST中右节点都大于根结点
    int j = i;
    for ( j = 0; j < len; j++)
    {
        if (sq[j] < root)
        {
            return false;
        }
        
    }
    //判断左子树是不是二叉树
    bool l = true;
    if (i > 0)
    {
        l = VerifySquenceofBST(sq, i);
    }
    bool r = true;
    if (i < len - 1)
    {
        r = VerifySquenceofBST(sq+i, len - i - 1);
    }
    return (l && r);
}