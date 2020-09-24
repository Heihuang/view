/*
题目：给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先
最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。
解法：
根据二叉搜索树的特点，第一个值介于[p->val, q->val]之间的节点即为所求
代码中第二个和第三个if都和p->val比较是完全ok的，因为假如当p无论是两者中较小值还是较大值，介于[p->val, q->val]的情况已经被第一个ifmatch到了。
因此假如是大于p的值，则是同时大于p和q的值的。小于同理
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if((root -> val - p->val)*(root -> val - q ->val) <= 0 ){
        return root;
    }
    if(root -> val > p -> val){
        return lowestCommonAncestor(root -> left, p, q);
    }
    if(root -> val < p -> val){
        return lowestCommonAncestor(root -> right, p, q);
    }
    return NULL;
}

