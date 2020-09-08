/*
题目：我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。
求按从小到大的顺序的第 n 个丑数
解法：最终的丑数序列实际上就是这 3 个有序序列对的合并结果， 计算丑数序列也就是相当于 合并 3 个有序序列
*/
#include <vector>
#include <math.h>
using namespace std;

int nthUglyNumber(int n) {
    vector<int> dp(n, 0);
    dp[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] * 5);
        if (dp[i] == dp[p2] * 2)
            p2++;
        if (dp[i] == dp[p3] * 3)
            p3++;
        if (dp[i] == dp[p5] * 5)
            p5++;
    }
    return dp[n - 1];
}
