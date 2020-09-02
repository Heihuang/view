/*
题目：请实现一个函数，用来判断一棵二叉树是不是对称的。
如果一棵二叉树和它的镜像一样，那么它是对称的
解法：判断一棵树是否是对称的二叉树，可先将二叉树进行镜像旋转，如果还是本身，那么说明这是一棵对称的二叉树
*/

 bool isSymmetric(TreeNode* root) {
    TreeNode* sym = symetric(root);//进行镜像旋转，得到一棵新的二叉树
    if(isSame(sym,root))
        return true;
    else
        return false;
}

//进行镜像转换
TreeNode* symetric(TreeNode* root){
    if(root==NULL) return NULL;
    TreeNode* res = new TreeNode(root->val);
    res->left = symetric(root->right);
    res->right = symetric(root->left);
    return res;
}

//判断两棵二叉树是否相等
bool isSame(TreeNode* a,TreeNode* b){
    if(a==NULL&&b==NULL) return true;
    if(a==NULL&&b!=NULL) return false;
    if(a!=NULL&&b==NULL) return false;
    if(a->val==b->val){
        return isSame(a->left,b->left)&&isSame(a->right,b->right);
    }
    return false;
}

