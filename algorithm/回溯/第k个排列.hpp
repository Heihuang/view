/*
题目：给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如，下给定 n 和 k，返回第 k 个排列
解法：
*/
class Solution {
public:
    int mul(int num){
        // 返回num的阶乘
        int ans = 1;
        for(int i=1; i<=num; i++)   ans *= i;
        return ans;
    }
    string getPermutation(int n, int k) {
        vector<int> v;   // 存放当前的数字
        for(int i=1; i<=n; i++)   v.push_back(i);
        string ans = "";
        while(n){
            int cur_sum = mul(n-1);  //当前阶乘
            // k-1是边界的一个处理，比如n=3,k=4时，因为用的是闭区间[]，不减一的话边界统一不起来，会成为[)
            int t = (k-1) / cur_sum;  //当前最高位要填v[t]
            ans += ('0'+v[t]);
            v.erase(v.begin()+t);
            k -= (t * cur_sum);
            n--;
        }
        return ans;
    }
};

