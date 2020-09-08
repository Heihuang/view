/*
题目：请实现两个函数，分别用来序列化和反序列化二叉树。
解法：序列化时使用队列， 逻辑很清晰
反序列化时，先将生成的TreeNode*放入vector中。迭代vector构造树
迭代每个vec[i]，使用j保存i的左子下标。
*/

string serialize(TreeNode* root) {
    ostringstream out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* tmp = q.front();
        q.pop();
        if (tmp) {
            out<<tmp->val<<" ";
            q.push(tmp->left);
            q.push(tmp->right);
        } else {
            out<<"null ";
        }
    }
    return out.str();
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    istringstream input(data);
    string val;
    vector<TreeNode*> vec;
    while (input >> val) {
        if (val == "null") {
            vec.push_back(NULL);
        } else {
            vec.push_back(new TreeNode(stoi(val)));
        }
    }
    int j = 1;                                          // i每往后移动一位，j移动两位，j始终是当前i的左子下标
    for (int i = 0; j < vec.size(); ++i) {              // 肯定是j先到达边界，所以这里判断j < vec.size()
        if (vec[i] == NULL) continue;                   // vec[i]为null时跳过。
        if (j < vec.size()) vec[i]->left = vec[j++];    // 当前j位置为i的左子树
        if (j < vec.size()) vec[i]->right = vec[j++];   // 当前j位置为i的右子树
    }
    return vec[0];
}
