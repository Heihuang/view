#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>

string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    string ans;
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i + l < n; ++i) {
            int j = i + l;
            if (l == 0) {
                dp[i][j] = 1;
            } else if (l == 1) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            if (dp[i][j] && l + 1 > ans.size()) {
                ans = s.substr(i, l + 1);
            }
        }
    }
    return ans;
}

/*
中心扩展法
*/
string longestPalindrome(string s) {
    int len=s.size();
    if(len==0||len==1)
        return s;
    int start=0;//记录回文子串起始位置
    int end=0;//记录回文子串终止位置
    int mlen=0;//记录最大回文子串的长度
    for(int i=0;i<len;i++)
    {
        int len1=expendaroundcenter(s,i,i);//一个元素为中心
        int len2=expendaroundcenter(s,i,i+1);//两个元素为中心
        mlen=max(max(len1,len2),mlen);
        if(mlen>end-start+1)
        {
            start=i-(mlen-1)/2;
            end=i+mlen/2;
        }
    }
    return s.substr(start,mlen);
    //该函数的意思是获取从start开始长度为mlen长度的字符串
}

int expendaroundcenter(string s,int left,int right)
//计算以left和right为中心的回文串长度
{
    int L=left;
    int R=right;
    while(L>=0 && R<s.length() && s[R]==s[L])
    {
        L--;
        R++;
    }
    return R-L-1;
}


int main(int argc, char** argv)
{
    const char* str = "babad";
    longestPalindrome(str);
    return 0;
}