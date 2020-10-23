/*
题目：给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第n项，注意：整数序列中的每一项将表示为一个字符串。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
1.     1
2.     11
3.     21
4.     1211
5.     111221
*/
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string previous = countAndSay(n-1), result = ""; // 使用递归来一层一层往前推
        int count = 1; // count用来计数

        for(int i=0;i<previous.length();i++)
        {
            if(previous[i] == previous[i+1])
            {
                count ++; // 比如previous是111221时，111部分会让count=3，此时i在第三个1处
            }
            else
            {
                result += to_string(count) + previous[i]; // result会从空变成“31”（当i在第三个1处时）
                count = 1; // 由于i在第三个1处时，i+1处的值为2，1 != 2，所以count重新变成1
            }
        }

        return result;
    }
};