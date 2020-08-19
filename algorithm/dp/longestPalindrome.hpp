#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>

std::string longestPalindrome(const char* str)
{
    if (str == nullptr)
    {
        return "";
    }
    int len = strlen(str);
    if (len < 2)
    {
        return str;
    }
    int maxlen = 1;
    int begin = 0;
    std::string substr;
    std::vector<int> tp(len);
    std::vector<std::vector<int> > dp;
    for (size_t i = 0; i < len; i++)
    {
        dp.push_back(tp);
    }
    for (size_t r = 1; r < len; r++)
    {
        for (size_t l = 0; l < r; l++)
        {
            //如果两边值相等
            if (str[l] == str[r] )
            {
                //字符串长度不超过3，去掉两边就只剩下一个或没有，就判断为回文
                if (r -l < 3)
                {
                    dp[l][r] = 1;
                }
                else
                {
                    //如果字符串长度超过3,去掉两边后剩下的部分也是回文
                    dp[l][r] = dp[l+1][r-1];
                }
            }
            //记录最大值和起始值
            if (dp[l][r] && r-l+1 > maxlen)
            {
                /* code */
                maxlen = r-l+1;
                begin = l;
            }
        }
        
    }
    substr.assign(str+begin, maxlen);
    return substr;
}

int main(int argc, char** argv)
{
    const char* str = "babad";
    longestPalindrome(str);
    return 0;
}