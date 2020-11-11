/*
题目：
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
提示：a + b 意味着字符串 a 和 b 连接。

解法：首先如果s1 + s2 != s3,那s3必然不可能由s1和s2交错组成。在s1+s2==s3时，可以用动态规划。
定义f(i,j)表示s1的前i个元素和s2的前j个元素是否能交错组成s3的前i+j 个元素。如果s1的第i个元素和s3的第
i+j个元素相等，那么s1的前i个元素和s2的前j个元素是否能交错组成s3的前i+j个元素取决于s1的前i-1个元素和s2的前
j个元素是否能交错组成s3的前i+j-1个元素，即此时f(i,j)取决于f(i-1,j),在此情况下如果f(i -1, j)为真，
则f(i,j)也为真，同样的，如果s2的第j个元素和s3的第i+j个元素相等并且f(i, j - 1)为真，则f(i,j)也为真。
f(i,j) = [f(i - 1, j) and s1(i - 1) == s3(p)] or [f(i, j - 1) and s2(j - 1) == s3(p)]
p = i + j - 1
边界 f(0,0) = True
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto f = vector < vector <int> > (s1.size() + 1, 
        vector <int> (s2.size() + 1, false));

        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n + m != t) {
            return false;
        }

        f[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }

        return f[n][m];
    }
};
