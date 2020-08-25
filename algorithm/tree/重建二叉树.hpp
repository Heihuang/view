/*
题目：输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
解题思路：
二叉树的前序遍历顺序是：根节点、左子树、右子树，每个子树的遍历顺序同样满足前序遍历顺序。
二叉树的中序遍历顺序是：左子树、根节点、右子树，每个子树的遍历顺序同样满足中序遍历顺序
*/
#include <vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
        //二叉树的前序遍历中的第一位一定是根节点
        if(preorder.size()==0||inorder.size()==0)return nullptr;
        //找到根节点在中序遍历中的位置，中序遍历之前的节点都是左子树节点，之后都是右子树节点
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);  
    }

    TreeNode* build(vector<int>& preorder,int a1,int b1,vector<int>& inorder,int a2,int b2){
        TreeNode* root=new TreeNode(preorder[a1]);//创建当前的根节点
        int i=a2;
        while(inorder[i]!=preorder[a1])i++;//找到当前根节点在中序遍历中的位置i
        int left=i-a2;   //左子树的长度
        int right=b2-i;  //右子树的长度
        if(left>0)root->left=build(preorder,a1+1,a1+left,inorder,a2,i-1);
        if(right>0)root->right=build(preorder,a1+left+1,b1,inorder,i+1,b2);
        return root;
    }

