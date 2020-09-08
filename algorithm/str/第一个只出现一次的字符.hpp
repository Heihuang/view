/*
题目：在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。
s只包含小写字母
解法：用unordered_map存储字符，字符出现，则计数加1
*/
#include <string>
#include <unordered_map>
using namespace std;

char firstUniqChar(string s) {
    if(s == "")
        return ' ';
    //map中是对应字符出现的次数
    unordered_map<char,int> cmap;
    for(auto i = 0;i < s.size();i++)
    {
        cmap[s[i]]++;
    }
    //按字符串的顺序在map中查找到第一个出现一次的字符
    for(auto i = 0;i < s.size();i++)
    {
        if(cmap[s[i]] == 1)
            return s[i];
    }
    //没有找到
    return ' ';
}