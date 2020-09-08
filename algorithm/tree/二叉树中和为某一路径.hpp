/*
题目：输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径，从树的根结点开始往下一直到叶节点
所经过的节点形成一条路径。
解法：当前序遍历的方式访问到某个节点时，我们把该节点添加到路径上，并累加该节点的值，
如果该节点为叶节点并且路径中节点
的和刚好等于输入的整数，则当前路径符合要求。如果当前节点不是叶子节点，
则继续访问它的子节点。当前节点访问结束后，递归函数
将自动回到它的父节点，因此在函数退出之前要在路径上删除当前节点并减去当前节点的值，
以确保返回父节点时路径刚好是从根结点
到父节点的路径
*/

#include "BInaryTree.h"
#include <vector>
#include <stdio.h>
using namespace std;

vector<vector<int> > all_path;
// 此处sub_path使用引用而不是传值，可以节省大量时间，传值在迭代过程中，会大量复制构造函数，耗时会加大
void find_path(TreeNode* root, int sum, vector<int>& sub_path) {
    if (root == nullptr) {
        return;
    }
    sub_path.emplace_back(root->val);
    if (sum == root->val && root->left == nullptr && root->right == nullptr) {
        all_path.emplace_back(sub_path);
    }
    find_path(root->left, sum - root->val, sub_path);
    find_path(root->right, sum - root->val, sub_path);
    sub_path.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if (root == nullptr) {
        return all_path;
    }
    vector<int> sub_path;
    find_path(root, sum, sub_path);
    return all_path;
}