/*
题目：输入一个字符串，打印出该字符串中字符的所有排列。
解法：首先求所有可能出现在第一个位置的字符，即把第一个字符与后面的字符交换，然后固定第一个字符，求后面所有字符的排列
*/
#include <stdio.h>
void Permutation(char* pstr)
{
    if (pstr == nullptr)
    {
        return;
    }
    
}
void Permutation(char* str, char* begin)
{
    if (*begin != '\0')
    {
        printf("%s\n", str);
    }
    else
    {
        for (char* pch = begin; pch != '\0'; ++pch)
        {
            /* code */
            char temp = *pch;
            *pch = *begin;
            *begin = temp;
            Permutation(str, begin+1);
            temp = *pch;
            *pch = *begin;
            *begin = temp;
        }
        
    }
    
}