/*
题目：验证给定的字符串是否可以解释为十进制数字
*/
class Solution {
public:
    bool isNumber(string s) {
        // 去除首尾空格
        int len = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == ' ') len++;
            else break;
        }
        s = s.substr(0, s.size() - len);
        len = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ') len++;
            else break;
        }
        s = s.substr(len);

        if(s.size() == 0) return false;
        int index = 0; // 记录当前判断位置

        // 判断整数部分是否 是可带符号数字
        bool isNum = scanInt(s, index);

        // 判断小数部分
        if(s[index] == '.')
        {
            index++;

            // 小数点前面有带符号数字 或者 小数点后面有数字 即可
            isNum = isNum | scanUnsignedInt(s, index) ;
        }

        // 判断指数部分
        if(s[index] == 'e' || s[index] == 'E')
        {
            index++;

            // e或者E的前面 得是符合要求数字，并且后面 得是可带符号的数字
            isNum = isNum & scanInt(s, index);
        }

        return isNum & (index == s.size());
    }

    bool scanInt(string & s, int& index){
        if(s[index] == '+' || s[index] == '-')
        {
            index++;
        }
        return scanUnsignedInt(s, index);
    }

    bool scanUnsignedInt(string & s, int& index)
    {
        bool flag = false;
        while(s[index] >= '0' && s[index] <= '9' && index < s.size())
        {
            index++;
            flag = true;
        }
        return flag;
    }
};

