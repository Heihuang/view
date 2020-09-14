/*
题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，
标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。
*/
#include <string>
using namespace std;

string reverseWords(string s) {
    if(s.empty())return s;
    int len = 0;
    string ans = "";
    for(int m = s.size()-1; m >=0; m--)
    {
        if(s[m]==' '&&len!=0)
        {
            ans += s.substr(m+1,len)+ " ";len = 0; continue;
        }
        if(s[m]!= ' ')len++;
    }
    if(len !=0) ans += s.substr(0,len) + " ";
    if(ans.size()>0)ans.erase(ans.size()-1,1);
    return ans;

}
