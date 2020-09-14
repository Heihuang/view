/*
题目：输入一棵二叉树的根节点，求该树的深度。
从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度
解法：DFS/BFS
*/
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int maxDepth(TreeNode* root) {
    queue<TreeNode*> q;
    if (root) q.push(root);
    int ans = 0;
    while (!q.empty()) {
        for (int i = q.size() - 1; i >= 0; --i) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        ++ans;
    }
    return ans;
}

