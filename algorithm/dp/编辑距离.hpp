/*
题目：
解法：
d[i][j-1]为A的前i个字符和B的前j-1个字符编辑距离的子问题，即对于B的第j个字符，我们在A的末尾添加了一个相同的字符，
那么d[i][j]最小可以为d[i][j-1]+1
d[i-1][j]为A的前i-1个字符和B的前j个字符编辑距离的子问题。即对于A的第i个字符，我们在B的末尾添加了一个相同的字符，那么d[i][j]最小
可以为d[i-1][j]+1
d[i-1][j-1]为A前i-1个字符和B的前j-1个字符编辑距离的子问题。即对于B的第j个字符，我们修改A的第i个字符使它们相同，那么d[i][j]最小
可以为d[i-1][j-1]+1,特别的，如果A的第i个字符和B的第j个字符原本就相同，那么不用修改,d[i][j]最小可以为d[i-1][j-1]
若A和B的最后一个字母相同：d[i][j] = 1+min(d[i][j-1], d[i-1][j], d[i-1][j-1]-1)
若A和B的最后字母不同：d[i][j] = 1 + min(d[i][j-1], d[i-1][j], d[i-1][j-1])
边界：d[i][0] = i d[0][j] = j
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // 有一个字符串为空串
        if (n * m == 0) return n + m;

        // DP 数组
        int D[n + 1][m + 1];

        // 边界状态初始化
        for (int i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            D[0][j] = j;
        }

        // 计算所有 DP 值
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = D[i - 1][j] + 1;
                int down = D[i][j - 1] + 1;
                int left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                D[i][j] = min(left, min(down, left_down));

            }
        }
        return D[n][m];
    }
};


