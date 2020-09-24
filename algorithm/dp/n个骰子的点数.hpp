/*
题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率
思路：使用动态规划解决问题一般分为三步：
表示状态
找出状态转移方程
边界处理

首先用数组的第一维来表示阶段，也就是投掷完了几枚骰子。
然后用第二维来表示投掷完这些骰子后，可能出现的点数。
数组的值就表示，该阶段各个点数出现的次数。
所以状态表示就是这样的：dp[i][j]，表示投掷完i枚骰子后，点数j的出现次
状态转移方程：dp[n][j] += dp[n-1][j - i]
边界：dp[1][i] = 1;
*/
#include <vector>
using namespace std;
vector<double> twoSum(int n) {
    int dp[15][70];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 6; i ++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i ++) {
        for (int j = i; j <= 6*i; j ++) {
            for (int cur = 1; cur <= 6; cur ++) {
                if (j - cur <= 0) {
                    break;
                }
                dp[i][j] += dp[i-1][j-cur];
            }
        }
    }
    int all = pow(6, n);
    vector<double> ret;
    for (int i = n; i <= 6 * n; i ++) {
        ret.push_back(dp[n][i] * 1.0 / all);
    }
    return ret;
}
