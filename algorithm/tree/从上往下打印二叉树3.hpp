/*
题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，
第三行再按照从左到右的顺序打印，其他行以此类推
解法：利用双端队列，对树的每层都在不同方向出，不同方向进，就可以之字形顺序打印二叉树
*/
#include <vector>
#include <deque>
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    deque<TreeNode*> dq;
    vector<vector<int>> res;
    if(root == NULL) {
        return res;
    }
    dq.push_back(root);
    int turn = 0;
    while(!dq.empty()) {
        int size = dq.size();
        vector<int> layer;
        if(turn == 0) {
            while(size-- > 0) {
                TreeNode *temp = dq.front();
                dq.pop_front();
                layer.push_back(temp->val);
                if(temp->left != NULL) {
                    dq.push_back(temp->left);
                }
                if(temp->right != NULL) {
                    dq.push_back(temp->right);
                }
            }
            turn = 1;
        } else {
            while(size-- > 0) {
                TreeNode *temp = dq.back();
                dq.pop_back();
                layer.push_back(temp->val);
                if(temp->right != NULL) {
                    dq.push_front(temp->right);
                }
                if(temp->left != NULL) {
                    dq.push_front(temp->left);
                }
            }
            turn = 0;
        }
        res.push_back(layer);
    }
    return res;
}
