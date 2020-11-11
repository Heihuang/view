/*
题目：给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合
解法：
*/
class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; //用来存放符合条件单一结果
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { //控制树的横向遍历 优化的地方
            path.push_back(i); // 处理节点 
            backtracking(n, k, i + 1); 
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};
