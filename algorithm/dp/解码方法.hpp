/*
题目：
一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。
题目数据保证答案肯定是一个 32 位的整数。

解法：
dp[i]为str[0..1]的译码方法总数
若s[i] = '0',那么若s[i-1] = '1' or '2',则dp[i] = dp[i -2];否则return0
    s[i-1]+s[i]唯一被译码，不增加情况
若s[i-1] = '1',则dp[i] = dp[i-1]+dp[i-2]
    s[i-1]与s[i]分开译码，为dp[i-1],合并译码，为dp[i-2]
若s[i-1]='2' and '1' <= s[i] <= '6',则dp[i] = dp[i-1] + dp[i-2]
*/
int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int pre = 1, curr = 1;//dp[-1] = dp[0] = 1
    for (int i = 1; i < s.size(); i++) {
        int tmp = curr;
        if (s[i] == '0')
            if (s[i - 1] == '1' || s[i - 1] == '2') curr = pre;
            else return 0;
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            curr = curr + pre;
        pre = tmp;
    }
    return curr;
}
