/*
题目：给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18
解法：边界条件：dp[1] = dp[2] = 1，表示长度为 2 的绳子最大乘积为 1；
状态转移方程：dp[i] = max(dp[i], max((i - j) * j, j * dp[i - j]))

*/
#include <vector>
#include <math.h>
using namespace std;
int dp(int n, vector<int>& res){
    if(n <= 4) return n;
    int ans = n;
    for(int i = 1; i <= n/2; i ++){
        if(res[n - i] == 0) res[n - i] = dp(n - i, res);
        if(res[i] == 0) res[i] = dp(i, res);
        ans = max(ans, res[n - i]*res[i]);
    }
    return ans;
}
int cuttingRope(int n) {
    if(n == 2) return 1;
    if(n == 3) return 2;
    vector<int> res(n, 0);
    return dp(n, res); 
}