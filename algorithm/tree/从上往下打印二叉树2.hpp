/*
题目：从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
*/
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>r;
            int l=q.size();
            for(int i=0;i<l;i++){ //当前层节点都在队列中，依次取出
                TreeNode* t=q.front();
                r.push_back(t->val);
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            res.push_back(r);
        }
        return res;
}