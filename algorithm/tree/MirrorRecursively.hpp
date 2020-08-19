//二叉树镜像
//解题思路：我们先前序遍历这棵的每个节点，如果遍历到的节点有子节点，就交换它的两个子节点。
//当交换完所有非叶子节点的左右子节点后，就得到了树的镜像
 #include "BInaryTree.h"

 void MirroRecursively(BInaryTreeNode* pNode)
 {
     if (pNode == nullptr || (pNode->left == nullptr && pNode->right == nullptr))
     {
         /* code */
         return;
     }
     //交换左右子节点
     BInaryTreeNode* ptemp = pNode->left;
     pNode->left = pNode->right;
     pNode->right = ptemp;
     if (pNode->left)
     {
         /* code */
         MirroRecursively(pNode->left);
     }
     if (pNode->right)
     {
         /* code */
         MirroRecursively(pNode->right);
     }
     
 }