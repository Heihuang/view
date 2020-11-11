/*
题目：给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法
解法：使用set存储0所在的行列，避免行列重复
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
    set<int> rows,cols;
    int m = a.size(), n = a[0].size();
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(a[i][j] == 0)    
            {
                rows.insert(i);
                cols.insert(j);
            }
        }          
    }
    for(int r : rows)
    {
        for(int j = 0 ; j < n; ++j)
            a[r][j] = 0;
    }
    for(int c : cols)
    {
        for(int i = 0; i < m; ++i)
            a[i][c] = 0;
    }

    }
};
