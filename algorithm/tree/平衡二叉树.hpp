/*
题目：输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，
那么它就是一棵平衡二叉树
思路:前序遍历二叉树，比较每个根节点的左右高度差
1.若为空返回true
2.计算左子树和右子树的高度差 高度计算方式就是求二叉树的最大深度
3.所有节点都满足高度差小于等于1 返回true
4.否则有一个高度差大于1 则返回false
*/

bool isBalanced(TreeNode* root) {
    return !root ? true : abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
int depth(TreeNode* cur) { //计算二叉树的最大深度
    return !cur ? 0 : max(depth(cur->left), depth(cur->right)) + 1;
}

