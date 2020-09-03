//题目：从上往下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印
//解题要点：每一次打印一个节点的时候，如果该节点有子节点，
//则把该节点的子节点放到一个队列的末尾。
//接下来到队列的头部取出最早进入队列的节点，重复前面的打印操作，直到队列中的所有节点都被打印出来为止
#include "BInaryTree.h"
#include <deque>
void PrintFropTopToBottom(BInaryTreeNode* root)
{
    if (!root)
    {
        return;
    }
    std::deque<BInaryTreeNode*> dt;
    dt.push_back(root);
    while (!dt.empty())
    {
        /* code */
        BInaryTreeNode* node = dt.front();
        dt.pop_front();
        printf("v=%d", node->value);
        //如果有左子树节点，将左子树节点放入队列
        if (node->left)
        {
            dt.push_back(node->left);
        }
        //如果有右子树节点，将右子树节点放入队列
        if (node->right)
        {
            dt.push_back(node->right);
        }
        
    }
    
}